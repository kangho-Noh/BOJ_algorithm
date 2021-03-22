#include <iostream>
#include <stack>
using namespace std;

int stNode;
int adj[100][100]; //adj[i][j] : i -> j로 가는 간선의 수

void dfs(int n, stack<int>& E)
{
	for (int i = 0; i < n; i++)
	{
		if (adj[n][i] > 0)
		{
			//양방향 그래프이므로 양쪽으로 지워준다
			adj[n][i]--;
			adj[i][n]--;
			dfs(i, E);
		}
	}
	E.push(n);
}

stack<int> get_Euler()
{
	stack<int> E;
	dfs(stNode, E);
}

int main()
{
	stack<int> Euler;
	Euler = get_Euler();
}