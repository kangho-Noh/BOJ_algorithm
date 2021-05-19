#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
long long l;
char map[102][102];

struct robot {
	int y, x;
	char d;
	robot(){}
	bool operator== (const robot& r) {
		if (this->y == r.y && this->x == r.x && this->d == r.d) return true;
		else return false;
	}
};


bool check_turn(robot& r) {
	// 바라보는 방향이 벽이 아닐 때까지 돌기
	if (r.d == 'N' && map[r.y-1][r.x]=='#') {
		r.d = 'E';
		return true;
	}else if (r.d == 'S' && map[r.y+1][r.x] == '#') {
		r.d = 'W';
		return true;
	}else if (r.d == 'E' && map[r.y][r.x+1] == '#') {
		r.d = 'S';
		return true;
	}else if (r.d == 'W' && map[r.y][r.x-1] == '#') {
		r.d = 'N';
		return true;
	}

	else {
		return false;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while (1) {
		vector<robot> history;
		cin >> n >> m >> l;
		if (!n && !m && !l) break;

		for (int i = 0; i < 102; i++) {
			for (int j = 0; j < 102; j++) {
				map[i][j] = '#';
			}
		}
		robot r;
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			for (int j = 1; j <= m; j++) {
				char c; c = s[j - 1];
				if (c != '.' && c != '#') {
					r.y = i;
					r.x = j;
					r.d = c;
					map[i][j] = '.';
				}
				else map[i][j] = c;
			}
		}
		history.push_back(r);
		while (check_turn(r)) {}
		int div = 0;
		bool found = false;
		bool done = false;
		while (!found) {
			if (r.d == 'N') {
				r.y--;
			}
			else if (r.d == 'S') {
				r.y++;
			}
			else if (r.d == 'E') {
				r.x++;
			}
			else if (r.d == 'W') {
				r.x--;
			}

			//패턴 찾기 전에 끝나버릴 경우
			l--;
			if (l == 0) {
				done = true;
				break;
			}

			history.push_back(r);
			for (int i = 0; i < history.size()-1;i++) {
				if (history[i] == r) {
					found = true;
					div = int(history.size())-1 - i;
					break;
				}
			}
			if(!found)
			while (check_turn(r)) {}
		}
		if (done) {
			cout << r.y << ' ' << r.x << ' ' << r.d << '\n';
			continue;
		}
		l %= div;
		for (int i = 0; i < l; i++) {
			while (check_turn(r)) {}
			if (r.d == 'N') {
				r.y--;
			}
			else if (r.d == 'S') {
				r.y++;
			}
			else if (r.d == 'E') {
				r.x++;
			}
			else if (r.d == 'W') {
				r.x--;
			}
		}
		cout << r.y << ' ' << r.x << ' ' << r.d << '\n';
	}
}