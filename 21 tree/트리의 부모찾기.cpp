#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
int parent[100001];

void findParent(int now)
{
	int s = v[now].size();
	
	for (int i = 0; i < s; i++)
	{
		if (parent[v[now][i]] == 0)
		{
			parent[v[now][i]] = now;
			findParent(v[now][i]);
		}
	}
}

int main()
{
	int N; cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	parent[1] = -1;
	findParent(1);

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}
}