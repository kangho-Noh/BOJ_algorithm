#include <iostream>
#include <cstring>
using namespace std;

int N, map[100][100], chk[100][100];
bool ans;

void chkans(int y, int x)
{
	if (y >= N || x >= N) return;
	if (chk[y][x] > 0) return;
	chk[y][x]++;
	if (y == N - 1 && x == N - 1)
	{
		ans = true;
		return;
	}
	//»óÇÏÁÂ¿ì
	int d = map[y][x];
	chkans(y + d, x);
	chkans(y , x+d);
	return;
}

int main()
{
	int C; cin >> C;
	for (int k = 0; k < C; k++)
	{
		ans = false;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				chk[i][j] = 0;
			}
		}
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}
		chkans(0, 0);
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}