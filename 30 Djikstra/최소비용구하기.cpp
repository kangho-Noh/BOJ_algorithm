#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, S, F;
const int INF = 987654321;
vector<pair<int, int>> adj[1001]; //adj[i] (l, r) : i���ÿ��� r ���� ���µ� ��� ��� == l
priority_queue<pair<int, int>> pq; //(����ġ, ����)

vector<int> Djikstra(int st)
{
	vector<int> d(1001, INF);
	d[st] = 0;
	pq.push(make_pair(0,st));
	while (!pq.empty())
	{
		int cost = -pq.top().first; //���ݱ��� �°Ÿ� ���̳ʽ� ������ minheapó�� �۵��ϵ��� �������
		int here = pq.top().second; //���� �ִ°�
		pq.pop();
		//�̹� �Դ� ���̰�, �� �Ÿ��� �� ª�ٸ� �� ����
		if (cost > d[here]) continue;
		//���� �ִ� ������ �� �� �ִ� �� ���� �� �鸮��(bfs)
		for (int i = 0; i < adj[here].size(); i++)
		{
			int nextdis = adj[here][i].first + cost;
			int there = adj[here][i].second;
			// �ִܰŸ��� pq�� �־ ��� Ž���ϵ��� ����
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