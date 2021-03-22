#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int INF = 987654321;
int V, E, K;
vector<pair<int, int>> adj[20001]; //adj[i] = (가중치, 정점)
priority_queue<pair<int, int>> pq; //pq (가중치, 정점)

vector<int> djikstra(int st)
{
	vector<int> v(20001, INF);
	v[st] = 0;
	pq.push(make_pair(0, st));
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (v[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].second;
			int weight = adj[here][i].first + cost;
			if (v[there] > weight)
			{
				v[there] = weight;
				pq.push(make_pair(-weight, there));
			}
		}
	}
	return v;
}

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(0);
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(w, v));
	}
	vector<int> djik = djikstra(K);
	for (int i = 1; i <= V; i++)
	{
		if (djik[i] == INF) cout << "INF\n";
		else cout << djik[i] << '\n';
	}
}