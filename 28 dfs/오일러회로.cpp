#include <iostream>
#include <stack>
using namespace std;

int N, adj[1001][1001], chk[1001], degree[1001];
stack<int> Euler;

void dfs(int n)
{
	chk[n]++;
	for (int i = 0; i < N; i++)
	{
		if (!chk[i] && adj[n][i]) dfs(i);
	}
	return;
}

bool chk_Euler()
{
	// 0��° �������� �����ؼ� �׷��� Ž��
	dfs(0);
	// �ϳ��� ������Ʈ���� Ȯ��(�ϳ��� �������� ����ؼ� ��� ������ ��������)
	for (int i = 0; i < N; i++)
	{
		if (chk[i] == 0)
		{
			return false;
		}
	}

	// ��� ������ ������ ¦������ Ȯ��
	for (int i = 0; i < N; i++)
	{
		if (degree[i] % 2 == 1) return false;
	}
	return true;
}

void dfs_Euler(int n, stack<int>& E)
{
	for (int i = 0; i < N; i++)
	{
		if (adj[n][i] > 0)
		{
			adj[n][i]--;
			adj[i][n]--;
			dfs_Euler(i, E);
		}
	}
	E.push(n);
}

stack<int> get_Euler()
{
	stack<int> E;
	dfs_Euler(0, E);
	return E;
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a; cin >> a;
			if (adj[i][j] == 0 && a > 0)
			{
				adj[i][j] += a;
				adj[j][i] += a;
				degree[i] += a;
				degree[j] += a;
			}
		}
	}
	if (!chk_Euler())
	{
		cout << "-1\n";
		return 0;
	}
	stack<int> Euler = get_Euler();
	if (Euler.empty())
	{
		cout << "-1\n";
		return 0;
	}
	while (!Euler.empty())
	{
		cout << Euler.top() + 1 << ' '; //���� ��ȣ�� 1���� �����̹Ƿ�
		Euler.pop();
	}
}