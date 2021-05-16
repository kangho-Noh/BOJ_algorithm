#include <iostream>
#include <vector>
using namespace std;

int n, m, map[52][52];

struct yx {
	int x; int y;
	yx(int _y, int _x) {
		x = _x;
		y - _y;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	char a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			if (a != '-') {
				map[i][j] = a - '0';
			}
			else {
				map[i][j] = -1;
			}
		}
	}

}