#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T; cin>>T;
    while(T--){
        int n,m,p,q; cin>>n>>m>>p>>q;
        int chk[10001] = {0,};

        vector<pair<int,pair<int,int>>> adj;
        for(int i=0;i<m;i++){
            int u,v,w; cin>>u>>v>>w;
            adj.push_back(make_pair(w,make_pair(u,v)));


        }
        sort(adj.begin(), adj.end());
        bool res = false; //p q 이어지면 true
        for(auto i:adj){
            int city1 = i.second.first;
            int city2 = i.second.second;
            if(chk[city1] && chk[city2]) continue;
            chk[city1]++; chk[city2] ++;
            if((city1==p&&city2==q)||(city1==q&&city2==p)){
                res = true;
                break;
            }
        }
        if(res) cout<<"YES\n";
        else cout << "NO\n";
    }
}