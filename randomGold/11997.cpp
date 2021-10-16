//좌표압축, 누적합 2차원
#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int Sum[1001][1001];

int rangeSum(int x1,int y1, int x2, int y2){
    return Sum[x2][y2] - Sum[x2][y1] - Sum[x1][y2] + Sum[x1][y1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin>>n;
    int M;
    int x[1001], y[1001], X=0, Y=0;
    unordered_map<int,int> xhash,yhash;
    set <int> xset,yset;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        xset.insert(x[i]);
        yset.insert(y[i]);
    }
    for (int i:xset) {
        xhash[i]=X++;
    }
    for(int i:yset){
        yhash[i]=Y++;
    }
    int A[1001][1001] = {0,};
    for(int i=0;i<n;i++){
        ++A[xhash[x[i]]][yhash[y[i]]];
    }
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            Sum[i+1][j+1] = Sum[i+1][j]+Sum[i][j+1]-Sum[i][j]+A[i][j];
        }
    }
    int res = n;
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            int temp = max(rangeSum(0, 0, i, j), rangeSum(i, j, X, Y));
            temp = max(rangeSum(0, j, i, Y), temp);
            temp = max(rangeSum(i, 0, X, j), temp);
            res = min(temp, res);
        }
    }
    cout<<res<<'\n';
}