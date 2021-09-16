//
// Created by �밭ȣ on 2021/09/16.
//

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> adj[10001];
int chk[10001];
int max_hap;
int max_node;

void dfs(int now, int hap){

    if(max_hap<hap){
        max_node = now;
        max_hap = hap;
    }
    chk[now]++;
    for(pair<int,int> p : adj[now]){
        if(chk[p.first]) continue;
        dfs(p.first, hap+p.second);
    }
    chk[now]--;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    int ans = 0;
    for(int i=0;i<n-1;i++){
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    dfs(1,0);
    dfs(max_node, 0);
    ans = max_hap;
    cout<<ans<<'\n';
}