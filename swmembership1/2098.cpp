#include<bits/stdc++.h>
using namespace std;

int adj[20][20]; //간선의 크기
int cost[20][1<<20]; //[now][bit] now의 위치에서 bit만큼 방문했을 때의 최소값 memoization
int n;

int TSP(int now, int bit){

    if(bit == (1<<n) -1){
        if(adj[now][0]==0) return 1e9;
        else return adj[now][0];
    }
    int& ret = cost[now][bit];
    if(ret!=-1){ //같은 과정으로 온 적이 있으면
        return ret;
    }
    ret = 1e9;

    for(int i=0;i<n;i++){
        if(adj[now][i] ==0 )continue; // 갈 수 없음
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