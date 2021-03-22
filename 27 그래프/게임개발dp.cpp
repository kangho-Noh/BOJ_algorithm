#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int buildtime[501], ans[501], chk[501];
vector<int> pre[501];

int dfs(int now)
{
	if (ans[now]) return ans[now];
	int si = pre[now].size();
	chk[now]++;
	int maxt = 0;
	for (int i = 0; i < si; i++)
	{
		int nxt = pre[now][i];
		if (!chk[nxt]) maxt = max(maxt, dfs(nxt));
	}
	return maxt + buildtime[now];
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> buildtime[i];
		while (1)
		{
			int a; cin >> a;
			if (a == -1) break;
			pre[i].push_back(a);
		}
		if (pre[i].empty()) ans[i] = buildtime[i];
	}
	for (int i = 1; i <= N; i++)
	{
		memset(chk, 0, sizeof(chk));
		ans[i] = dfs(i);
		cout << ans[i] << '\n';
	}
}