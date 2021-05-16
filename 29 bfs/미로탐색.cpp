//https://www.acmicpc.net/problem/2178
#include <iostream>
#include <queue>
using namespace std;

struct yx {
	int y, x;
	yx(int _y, int _x){
		y = _y;
		x = _x;
	}
};

int mp[102][102], chk[102][102];
queue<yx> q, nxtq;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1,-1,0,0 };

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			mp[i][j] = s[j] - '0';
		}
	}
	int ans = 0;
	q.push(yx(0, 0));
	chk[0][0]++;
	bool found = false;
	while (!found && !q.empty()) {
		while (!q.empty()) {
			yx now = q.front();
			q.pop();
			int nowy = now.y;
			int nowx = now.x;
			if (nowy == n - 1 && nowx == m - 1) {
				found = true;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nxty = nowy + dy[i];
				int nxtx = nowx + dx[i];
				if (nxty < 0 || nxtx < 0 || nxty >= n || nxtx >= m) continue;
				if (mp[nxty][nxtx] && !chk[nxty][nxtx]) {
					nxtq.push(yx(nxty, nxtx));
					chk[nxty][nxtx]++;
				}
			}
		}
		while (!nxtq.empty()) {
			yx a = nxtq.front();
			nxtq.pop();
			q.push(a);
		}

		ans++;
	}
	cout << ans << '\n';
}