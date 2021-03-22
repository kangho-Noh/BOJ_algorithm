#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct yx
{
	int y; int x; int depth;
	yx(int _y, int _x, int _d)
	{
		y = _y;
		x = _x;
		depth = _d;
	}
};

int l;
int nowy, nowx;
int goaly, goalx;
int goy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int gox[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int chk[301][301];
queue<yx> qnow;

int main()
{
	int C; cin >> C;
	for (int ci = 0; ci < C; ci++)
	{
		while (!qnow.empty()) qnow.pop();
		cin >> l;
		cin >> nowx >> nowy;
		cin >> goalx >> goaly;
		bool found = false;
		int ans = 0;
		qnow.push(yx(nowy, nowx, 0));
		memset(chk, 0, sizeof(chk));
		while (!found)
		{
			while (!qnow.empty())
			{
				yx yxtop = qnow.front();
				qnow.pop();
				int ny = yxtop.y;
				int nx = yxtop.x;
				int nd = yxtop.depth;
				chk[ny][nx]++;
				if (ny == goaly && nx == goalx)
				{
					found = true;
					ans = nd;
					break;
				}
				for (int i = 0; i < 8; i++)
				{
					int yy = ny + goy[i];
					int xx = nx + gox[i];
					if (yy >= 0 && yy < l && xx >= 0 && xx < l)
						if (!chk[yy][xx])
						{
							qnow.push(yx(yy, xx, nd + 1));
							chk[yy][xx]++;
							if (yy == goaly && xx == goalx)
							{
								found = true;
								ans = nd + 1;
								break;
							}
						}
				}
				if (found) break;
			}
		}
		cout << ans << '\n';
	}
}