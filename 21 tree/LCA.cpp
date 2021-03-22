#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> con[100001]; // 연결된 두 정점
int parent[100001]; // parent[n] == n번 노드의 조상노드 vector
int depth[100001]; // n번 노드의 깊이


void findParent(int now, int dep)
{
	int s = con[now].size();
	depth[now] = dep;
	for (int i = 0; i < s; i++)
	{
		int kid = con[now][i];
		if (parent[kid] == 0) //부모가 없으면 now가 부모
		{
			parent[kid] = now;
			findParent(kid, dep+1);
		}
	}
}

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> N;
	int a, b;
	for (int i = 0; i < N-1; i++)
	{
		cin >> a >> b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	parent[1] = 1;
	findParent(1, 0);
	
	cin >> M;
	int da, db, tmp, ans, pa, pb;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		ans = 1;
		da = depth[a];
		db = depth[b];
		if (da > db) //da<=db
		{
			tmp = da;
			da = db;
			db = tmp;
			tmp = a;
			a = b;
			b = tmp;
		}
		pa = a;
		pb = b;
		for (int i = 0; i < db - da; i++)
		{
			pb = parent[pb];
		}
		for (int i = da; i >= 0; i--)
		{
			if (pa == pb)
			{
				ans = pa; break;
			}
			pa = parent[pa];
			pb = parent[pb];
		}
		cout << ans << '\n';
	}
}