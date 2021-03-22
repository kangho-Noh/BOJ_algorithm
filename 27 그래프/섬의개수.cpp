#include <iostream>
#include <cstring>
using namespace std;

int map[50][50], chk[50][50];
int w, h, ans;

int dfs(int i, int j)
{
	if (i < 0 || j < 0 || i >= h || j >= w) return 0;
	if (map[i][j] == 0 || chk[i][j] == 1) return 0;
	if (map[i][j] == 1 && chk[i][j] == 0)
	{
		chk[i][j]++;
		for (int k = -1; k < 2; k++)
		{
			for (int w = -1; w < 2; w++)
			{
				if(k || w) dfs(i + k, j + w);
			}
		}
		return 1;
	}
	return 0;
}

void dfsall()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (dfs(i, j)) ans++;
		}
	}
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	while (1)
	{
		cin >> w >> h;
		ans = 0;
		memset(map, 0, sizeof(map));
		memset(chk, 0, sizeof(chk));
		if (!w && !h) break;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}
		dfsall();
		cout << ans << '\n';
	}
}