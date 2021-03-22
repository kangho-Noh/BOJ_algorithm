#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, S, F;
const int INF = 987654321;
vector<pair<int, int>> adj[1001]; //adj[i] (l, r) : i도시에서 r 도시 가는데 드는 비용 == l
priority_queue<pair<int, int>> pq; //(가중치, 정점)

vector<int> Djikstra(int st)
{
	vector<int> d(1001, INF);
	d[st] = 0;
	pq.push(make_pair(0,st));
	while (!pq.empty())
	{
		int cost = -pq.top().first; //지금까지 온거리 마이너스 이유는 minheap처럼 작동하도록 만드려고
		int here = pq.top().second; //지금 있는곳
		pq.pop();
		//이미 왔던 곳이고, 그 거리가 더 짧다면 걍 버림
		if (cost > d[here]) continue;
		//지금 있는 곳에서 갈 수 있는 곳 전부 다 들리기(bfs)
		for (int i = 0; i < adj[here].size(); i++)
		{
			int nextdis = adj[here][i].first + cost;
			int there = adj[here][i].second;
			// 최단거리면 pq에 넣어서 계속 탐색하도록 만듦
			if (d[there] > nextdis)
			{
				d[there] = nextdis;
				pq.push(make_pair(-nextdis, there));
			}
		}
	}
	return d;
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int q, w, e; cin >> q >> w >> e;
		adj[q].push_back(make_pair(e, w));
	}
	cin >> S >> F;
	vector<int> d = Djikstra(S);
	cout << d[F] << '\n';
}