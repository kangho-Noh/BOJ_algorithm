#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, map[101][101], chk[101][101], ans;
vector<int> area;

void get_area(int y, int x)
{
	if (y < 0 || x < 0 || y >= M || x >= N) return;
	if (chk[y][x] == 1 || map[y][x] == 1) return;
	chk[y][x] = 1;
	ans++;
	get_area(y - 1, x);
	get_area(y + 1, x);
	get_area(y, x - 1);
	get_area(y, x + 1);
}

int main()
{
	cin >> M >> N >> K;
	for (int t = 0; t < K; t++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				map[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans = 0;
			get_area(i, j);
			if(ans)
				area.push_back(ans);
		}
	}
	sort(area.begin(), area.end());
	cout << area.size() << '\n';
	for (int i : area)
	{
		cout << i << ' ';
	}
	cout << '\n';
}