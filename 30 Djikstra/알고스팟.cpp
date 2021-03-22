#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct room
{
	int y, x;
	int visit_cnt;
	room(int _y, int _x, int v)
	{
		y = _y;
		x = _x;
		visit_cnt = v;
	}
	bool operator<(const room& r) const
	{
		if (this->visit_cnt > r.visit_cnt) return true;
		else return false;
	}
};

int INF = 987654321;
int N, M;
int map[102][102]; //1¿Ã ∫Æ, 0¿Ã ∫ÛπÊ
priority_queue<room> pq;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int find_ans()
{
	vector<vector<int>> ans(102, vector<int>(102, INF));
	ans[1][1] = 0;
	pq.push(room(1, 1, 0));
	while (!pq.empty())
	{
		int ny = pq.top().y;
		int nx = pq.top().x;
		int nv = pq.top().visit_cnt;
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nxty = ny + dy[i];
			int nxtx = nx + dx[i];
			int cost = nv;
			if (nxty<1 || nxtx<1 || nxty>N || nxtx>M)
			{
				continue;
			}
			if (map[nxty][nxtx] == 1) cost++;
			if (ans[nxty][nxtx] < cost)
			{
				continue;
			}
			if (ans[nxty][nxtx] > cost)
			{
				ans[nxty][nxtx] = cost;
				pq.push(room(nxty, nxtx, cost));
			}
		}
	}
	return ans[N][M];
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < M; j++)
		{
			map[i + 1][j + 1] = s[j] - '0';
		}
	}
	cout << find_ans() << '\n';
}