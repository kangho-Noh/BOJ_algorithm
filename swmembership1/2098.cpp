#include<bits/stdc++.h>
using namespace std;

int adj[20][20]; //������ ũ��
int cost[20][1<<20]; //[now][bit] now�� ��ġ���� bit��ŭ �湮���� ���� �ּҰ� memoization
int n;

int TSP(int now, int bit){

    if(bit == (1<<n) -1){
        if(adj[now][0]==0) return 1e9;
        else return adj[now][0];
    }
    int& ret = cost[now][bit];
    if(ret!=-1){ //���� �������� �� ���� ������
        return ret;
    }
    ret = 1e9;

    for(int i=0;i<n;i++){
        if(adj[now][i] ==0 )continue; // �� �� ����
        if((bit & (1<<i)) == (1<<i)) continue; // now == i

        ret = min(ret, adj[now][i] + TSP(i, bit | (1 << i)));
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    memset(cost, -1, sizeof(cost));
    cout<< TSP(0,1)<<'\n';
}