#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, buildtime[501], ans[501];
vector<int> v[501]; //v[i] : i 건물이 지어지기 위해 먼저 지어져야 하는 건물벡터
queue<int> q; //위상정렬 결과 담은 큐
int chk[501];

void dfs(int now)
{
	if (chk[now]) return;
	chk[now]++;
	int si = v[now].size();
	for (int i = 0; i < si; i++)
	{
		dfs(v[now][i]);
	}
	q.push(now);
	return;
}

void topological_sort()
{
	for (int i = 1; i <= N; i++)
	{
		dfs(i);
	}
}

int cal_buildtime(int now)
{
	if (ans[now]) return ans[now];
	int si = v[now].size();
	int maxt = 0;
	for (int i = 0; i < si; i++)
	{
		maxt = max(maxt, cal_buildtime(v[now][i]));
	}
	return maxt + buildtime[now];
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> buildtime[i];
		int a;
		while (1)
		{
			cin >> a;
			if (a == -1) break;
			v[i].push_back(a);
		}
		if (v[i].empty()) ans[i] = buildtime[i];
	}
	topological_sort();
	while(!q.empty())
	{
		int i = q.front();
		q.pop();
		ans[i] = cal_buildtime(i);
	}
	for (int i = 1; i <= N; i++)
	{
		cout << ans[i] << '\n';
	}
}