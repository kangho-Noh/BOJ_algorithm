//https://www.acmicpc.net/problem/17144
#include <iostream>
#include <cstring>
using namespace std;

int map[52][52], tmp[52][52]; //tmp�� �̼����� ���� �� �Ѳ����� ������ �迭
int r, c, t;
int aircleaner[2][2]; // map[aircleaner[0][0],aircleaner[0][1]] : ���� ����û���� ��ġ map[aircleaner[1][0],aircleaner[1][1]] : �Ʒ���

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
		//�̼����� ����
		memset(tmp, 0, sizeof(tmp));
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (map[i][j] != -1 && map[i][j] != 0)
				{
					int cnt = 0; //�ֺ� -1�� �ƴ� ĭ�� ��
					int dirt = map[i][j] / 5; //�ֺ����� ���� ����
					
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

		//����û���� ����
		//���� �ݽð� -> �� �� �� �� �� ������ �ű�� ������ġ : (aircleaner[0][0],aircleaner[0][1])
		int y = aircleaner[0][0], x = aircleaner[0][1];
		if (map[y][x - 1] != -1) //����û���Ⱑ ���ʺ��� �Ⱥپ��� ���
		{
			map[y][x - 1] = 0;
			x--;
		}
		else //����û���Ⱑ ���ʺ��� �پ��� ���
		{
			map[y - 1][x] = 0;
			y--;
		}
		
		//ĭ �ű��
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
		if (map[y][x + 1] != -1) //����û���Ⱑ �����ʺ��� �Ⱥپ��� ��� ����û���� ������ = 0
		{
			map[y][x + 1] = 0;
		}
		else //����û���Ⱑ �����ʺ��� �پ��� ��� ����û���� ���� = 0
		{
			map[y - 1][x] = 0;
		}

		//�Ʒ��� �ð� -> �� �� �� �� �� ������ �ű�� ������ġ : (aircleaner[1][0],aircleaner[1][1])
		y = aircleaner[1][0];
		x = aircleaner[1][1];
		if (map[y][x - 1] != -1) //����û���Ⱑ ���ʺ��� �Ⱥپ��� ���
		{
			map[y][x - 1] = 0;
			x--;
		}
		else //����û���Ⱑ ���ʺ��� �پ��� ���
		{
			map[y + 1][x] = 0;
			y++;
		}

		//ĭ �ű��
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
		if (map[y][x + 1] != -1) //����û���Ⱑ �����ʺ��� �Ⱥپ��� ��� ����û���� ������ = 0
		{
			map[y][x + 1] = 0;
		}
		else //����û���Ⱑ �����ʺ��� �پ��� ��� ����û���� �Ʒ��� = 0
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