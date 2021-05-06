#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[27][27], chk[27][27], n, ans, h;
vector<int> v;

void dfs(int y, int x) {
	if (y < 0 || x < 0 || y >= n || x >= n) return;
	if (map[y][x] == 0 || chk[y][x] == 1) return;

	h++;
	v[v.size() - 1] = max(h, v[v.size() - 1]);
	chk[y][x]++;
	dfs(y-1, x);
	dfs(y+1, x);
	dfs(y, x-1);
	dfs(y, x+1);
}

void dfs_all() {
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (map[i][j] ==1 && chk[i][j] == 0)
			{
				h = 0;
				v.push_back(0);
				dfs(i, j);
				ans++;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j] - '0';
		}
	}
	dfs_all();
	cout << ans << '\n';
	sort(v.begin(), v.end());
	for (int i : v)cout << i << '\n';
}