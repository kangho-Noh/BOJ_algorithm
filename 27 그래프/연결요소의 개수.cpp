#include <iostream>
using namespace std;

int con[1001][1001];
int chk[1001];
int N, M, ans;

int dfs(int now)
{
	if (chk[now]) return 0;
	chk[now]++;
	for (int i = 1; i <= N; i++)
	{
		if (con[now][i]) dfs(i);
	}
	return 1;
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		con[a][b] = con[b][a] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		if(dfs(i)) ans++;
	}
	cout << ans << '\n';
}