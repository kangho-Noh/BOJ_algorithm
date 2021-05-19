#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

int v, e, k;
vector<pair<int, int>> adj[20001];
priority_queue<pair<int, int>> pq; //(w,r) w가중치 r갈곳

vector<int> Djikstra(int st) {
	vector<int> ret(v+1, INF);
	ret[st] = 0;
	pq.push(make_pair(0, st));
	while (!pq.empty()) {
		int now = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();

		if (weight > ret[now]) continue;

		for (int i = 0; i < adj[now].size(); i++) {
			int there = adj[now][i].second;
			int cost = adj[now][i].first+weight;
			if (cost < ret[there]) {
				ret[there] = cost;
				pq.push(make_pair(-cost, there));
			}
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> v >> e>>k;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
	}
	vector<int> ans = Djikstra(k);
	for (int i = 1; i < ans.size();i++) {
		if (ans[i] == INF)cout << "INF\n";
		else cout << ans[i] << '\n';
	}
}