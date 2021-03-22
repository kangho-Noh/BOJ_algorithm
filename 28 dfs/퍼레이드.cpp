#include <iostream>
using namespace std;

int V, E;
int adj[3001][3001], degree[3001], chk[3001];

void dfs(int n)
{
	if (chk[n]) return;
	chk[n]++;
	for (int i = 1; i <= V; i++)
	{
		if (!chk[i] && adj[n][i])
		{
			dfs(i);
		}
	}
	return;
}

bool chk_Euler()
{
	//������׷��� ���Ϸ� ����� �ʿ��������
	//�ϳ��� ������Ʈ�� ������ �׷���������
	dfs(1);
	bool unique = true;
	for (int i = 1; i <= V; i++)
	{
		if (chk[i] == 0) unique = false;
	}
	if (!unique) return false;
	//��� ������ ������ ¦���� ���Ϸ� ȸ��, �� ������ ������ Ȧ���� ���Ϸ� ��� ����
	int hol = 0;
	for (int i = 1; i <= V; i++)
	{
		if (degree[i] % 2) hol++;
	}
	return (!hol || hol == 2);
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b; cin >> a >> b;
		adj[a][b]++;
		adj[b][a]++;
		degree[a]++;
		degree[b]++;
	}
	bool ans = chk_Euler();
	if (ans) cout << "YES\n";
	else cout << "NO\n";

}