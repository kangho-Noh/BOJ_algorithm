#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> adj[100001];
int isapart[100001];

int findother(int a, int before){
    int res = 0;
    for(int i=0;i<adj[a].size();i++){
        int next = adj[a][i].second;
        if(next == before) continue;
        if(isapart[next]) return 1;
        res = findother(next,a);
        if(res) return res;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k; cin>>n>>k;

    for(int i=0;i<n-1;i++){
        int a,b,c; cin>>a>>b>>c;
        adj[a].emplace_back(c,b);
        adj[b].emplace_back(c,a);
    }
    vector<int> apart;
    int chk[100001] = {0,};
    for(int i=0;i<k;i++){
        int a; cin>>a;
        apart.push_back(a);
        chk[a]++;
        isapart[a]++;
    }
    int res = k;
    for(int i:apart){
        int minn = 987654321;
        int closest;
        for(int j=0;j<adj[i].size();j++){
            int nowlen = adj[i][j].first;
            if(nowlen<minn){
                minn = nowlen;
                closest = adj[i][j].second;
            }
        }
        if(!chk[closest]){
            if(findother(closest, i)){
                res++;
                chk[closest]++;
            }
        }
    }
    cout<<res<<'\n';
}
