#include <iostream>
using namespace std;

int computer[101][101];
int chk[101];
int n, m;

void virus(int now)
{
	chk[now]++;
	for (int i = 1; i <= n; i++)
	{
		if (computer[now][i] && !chk[i])
		{
			virus(i);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		computer[a][b] = computer[b][a] = 1;
	}
	virus(1);
	int ans = -1;
	for (int i = 1; i <= n; i++) if (chk[i] != 0)ans++;
	cout << ans << '\n';
}