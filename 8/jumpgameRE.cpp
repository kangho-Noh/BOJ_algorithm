#include <iostream>
#include <cstring>
using namespace std;

int visited[101][101], chk[101][101], map[101][101], N;

int dp(int y, int x)
{
	if (y >= N || x >= N) return 0;
	if (y == N - 1 && x == N - 1) return 1;
	if (visited[y][x]) return chk[y][x];
	visited[y][x]++;
	chk[y][x]+=dp(y + map[y][x], x);
	chk[y][x]+=dp(y, x + map[y][x]);
	return chk[y][x];
}

int main()
{
	int C; cin >> C;
	for (int ci = 0; ci < C; ci++)
	{
		memset(chk, 0, sizeof(chk));
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		int ans = dp(0, 0);
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}