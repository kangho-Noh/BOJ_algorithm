#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 987654321;
int N, E, v1,v2;
vector<pair<int, int>> adj[801]; //adj[i] = i번째 정점에서 갈 수 있는 (cost, 정점) 간선 모음
priority_queue<pair<int, int>> pq; //(cost, 정점)

vector<int> Djikstra(int st)
{
	vector<int> v(801, INF);
	pq.push(make_pair(0, st));
	v[st] = 0;

	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		int si = adj[here].size();

		if (cost > v[here]) continue;

		for (int i = 0; i < si; i++)
		{
			int there = adj[here][i].second;
			int distance = adj[here][i].first + cost;
			//if (distance > v[there]) continue;
			if (distance < v[there])
			{
				v[there] = distance;
				pq.push(make_pair(-distance, there));
			}
		}
	}
	return v;
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	}
	cin >> v1 >> v2;
	vector<int> dis1 = Djikstra(1);
	vector<int> disv1 = Djikstra(v1);
	vector<int> disv2 = Djikstra(v2);
	int ans = min(dis1[v1] + disv1[v2] + disv2[N], dis1[v2] + disv2[v1] + disv1[N]);

	if (ans >= INF || E == 0) cout << "-1\n";
	else cout << ans << '\n';
}