//https://www.acmicpc.net/problem/17144
#include <iostream>
#include <cstring>
using namespace std;

int map[52][52], tmp[52][52]; //tmp는 미세먼지 퍼질 때 한꺼번에 더해줄 배열
int r, c, t;
int aircleaner[2][2]; // map[aircleaner[0][0],aircleaner[0][1]] : 위쪽 공기청정기 위치 map[aircleaner[1][0],aircleaner[1][1]] : 아래쪽

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> r >> c >> t;
	memset(map, -1, sizeof(map));
	int k = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				aircleaner[k][0] = i;
				aircleaner[k][1] = j;
				k++;
			}
		}
	}

	for (int T = 0; T < t; T++)
	{
		//미세먼지 퍼짐
		memset(tmp, 0, sizeof(tmp));
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (map[i][j] != -1 && map[i][j] != 0)
				{
					int cnt = 0; //주변 -1이 아닌 칸의 수
					int dirt = map[i][j] / 5; //주변으로 퍼질 먼지
					
					for (int dy = -1; dy < 2; dy += 2)
					{
						if (map[i + dy][j] != -1)
						{
							cnt++;
							tmp[i + dy][j] += dirt;
						}
					}
					for (int dx = -1; dx < 2; dx += 2)
					{
						if (map[i][j + dx] != -1)
						{
							cnt++;
							tmp[i][j + dx] += dirt;
						}
					}
					tmp[i][j] -= dirt * cnt;
				}
			}
		}
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if(map[i][j]!=-1)
					map[i][j] += tmp[i][j];
			}
		}

		//공기청정기 가동
		//위쪽 반시계 -> 왼 위 오 아 왼 순으로 옮기기 시작위치 : (aircleaner[0][0],aircleaner[0][1])
		int y = aircleaner[0][0], x = aircleaner[0][1];
		if (map[y][x - 1] != -1) //공기청정기가 왼쪽벽에 안붙었을 경우
		{
			map[y][x - 1] = 0;
			x--;
		}
		else //공기청정기가 왼쪽벽에 붙었을 경우
		{
			map[y - 1][x] = 0;
			y--;
		}
		
		//칸 옮기기
		while (map[y][x-1] != -1)
		{
			map[y][x] = map[y][x - 1];
			x--;
		}
		while (map[y - 1][x] != -1)
		{
			map[y][x] = map[y - 1][x];
			y--;
		}
		while (map[y][x + 1] != -1)
		{
			map[y][x] = map[y][x + 1];
			x++;
		}
		while (y != aircleaner[0][0])
		{
			map[y][x] = map[y + 1][x];
			y++;
		}
		while (x != aircleaner[0][1] + 1)
		{
			map[y][x] = map[y][x - 1];
			x--;
		}

		y = aircleaner[0][0];
		x = aircleaner[0][1];
		if (map[y][x + 1] != -1) //공기청정기가 오른쪽벽에 안붙었을 경우 공기청정기 오른쪽 = 0
		{
			map[y][x + 1] = 0;
		}
		else //공기청정기가 오른쪽벽에 붙었을 경우 공기청정기 위쪽 = 0
		{
			map[y - 1][x] = 0;
		}

		//아래쪽 시계 -> 왼 아 오 위 왼 순으로 옮기기 시작위치 : (aircleaner[1][0],aircleaner[1][1])
		y = aircleaner[1][0];
		x = aircleaner[1][1];
		if (map[y][x - 1] != -1) //공기청정기가 왼쪽벽에 안붙었을 경우
		{
			map[y][x - 1] = 0;
			x--;
		}
		else //공기청정기가 왼쪽벽에 붙었을 경우
		{
			map[y + 1][x] = 0;
			y++;
		}

		//칸 옮기기
		while (map[y][x - 1] != -1)
		{
			map[y][x] = map[y][x - 1];
			x--;
		}
		while (map[y + 1][x] != -1)
		{
			map[y][x] = map[y + 1][x];
			y++;
		}
		while (map[y][x + 1] != -1)
		{
			map[y][x] = map[y][x + 1];
			x++;
		}
		while (y != aircleaner[1][0])
		{
			map[y][x] = map[y - 1][x];
			y--;
		}
		while (x != aircleaner[1][1] + 1)
		{
			map[y][x] = map[y][x - 1];
			x--;
		}

		y = aircleaner[1][0];
		x = aircleaner[1][1];
		if (map[y][x + 1] != -1) //공기청정기가 오른쪽벽에 안붙었을 경우 공기청정기 오른쪽 = 0
		{
			map[y][x + 1] = 0;
		}
		else //공기청정기가 오른쪽벽에 붙었을 경우 공기청정기 아래쪽 = 0
		{
			map[y + 1][x] = 0;
		}

	}
	int ans = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j] != -1) ans += map[i][j];
		}
	}
	cout << ans << '\n';
}