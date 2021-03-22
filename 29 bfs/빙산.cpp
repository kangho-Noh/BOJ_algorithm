#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int map[302][302], nxt[302][302], chk[302][302];

void chk_dfs(int ny, int nx)
{
	if (ny<0 || nx<0 || ny >= N || nx >= M) return;
	if (chk[ny][nx]>0 || map[ny][nx] == 0) return;

	chk[ny][nx]++;
	chk_dfs(ny - 1, nx);
	chk_dfs(ny + 1, nx);
	chk_dfs(ny, nx - 1);
	chk_dfs(ny, nx + 1);
}

void melt_down()
{
	memset(nxt, 0, sizeof(nxt));
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (map[i][j] > 0)
			{
				int n = 0;
				if (map[i - 1][j] == 0) n++;
				if (map[i + 1][j] == 0) n++;
				if (map[i][j - 1] == 0) n++;
				if (map[i][j + 1] == 0) n++;
				nxt[i][j] = n;
			}
		}
	}
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (nxt[i][j] > 0)
			{
				map[i][j] -= nxt[i][j];
				if (map[i][j] < 0) map[i][j] = 0;
			}
		}
	}

	
}

int cal_ans(int ans)
{
	while (1)
	{
		int sy = 0, sx = 0;
		for (int i = 1; i < N-1; i++)
		{
			for (int j = 1; j < M-1; j++)
			{
				if (map[i][j] > 0)
				{
					sy = i;
					sx = j;
				}
			}
		}
		if (!sy && !sx) return 0; //얼음이 없거나 다 녹았음
		chk_dfs(sy, sx);
		for (int i = 1; i < N-1; i++)
		{
			for (int j = 1; j < M-1; j++)
			{
				if (chk[i][j] == 0 && map[i][j] > 0)
				{
					return ans;
				}
			}
		}
		memset(chk, 0, sizeof(chk));
		melt_down();
		ans++;
	}
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	bool ice_exist = false;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > 0) ice_exist = true;
		}
	}
	if (!ice_exist)
	{
		cout << "0\n";
		return 0;
	}
	int ans = cal_ans(0);
	cout << ans << '\n';
}