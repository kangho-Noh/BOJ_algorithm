#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
vector<pair<int,int>> adj[1001];
priority_queue<pair<int, int> > pq; //pq (����ġ, ����)

vector<int> djikstra(int st)
{
    vector<int> v(1001, 0);
    v[st] = 0;
    pq.push(make_pair(INF, st));
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (v[here] > cost) continue;

        for (int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].second;
            int weight = min(cost,adj[here][i].first);
            if (v[there] < weight)
            {
                v[there] = weight;
                pq.push(make_pair(weight, there));
            }
        }
    }
    return v;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    for(int ti=0;ti<t;ti++){
        int n,m,s,t; cin>>n>>m>>s>>t;
        for(int i=0;i<1001;i++){
            adj[i].clear();
        }
        for(int i=0;i<m;i++){
            int a,b,c; cin>>a>>b>>c;
            adj[a].push_back(make_pair(c,b));
            adj[b].push_back(make_pair(c,a));
        }
        vector<int> res = djikstra(s);
        cout<<res[t]<<'\n';
    }
}