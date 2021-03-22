#include <iostream>
using namespace std;

int w, h, ans, cnt_period, cnt;
char map[22][22];
int dx[4][2] = { {0,1},{1,1},{0,1},{-1,0} };//-1�� �����÷� �ȳ��� ����
int dy[4][2] = { {1,0},{0,1},{1,1},{1,1} }; 
//map[y+dy[0][0]][x+dx[0][0]]=='.' && map[y+dy[0][1]][x+dx[0][1]]=='.'

void boardcover(int y, int x)
{
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int y1 = y + dy[i][0];
		int x1 = x + dx[i][0];
		int y2 = y + dy[i][1];
		int x2 = x + dx[i][1];
		if (x1 < 0)
		{
			continue;
		}

		if (map[y1][x1] == '.' && map[y2][x2] == '.')
		{
			//�� ã��			
			if (cnt == cnt_period / 3)
			{
				ans++;
				cnt--;
				return;
			}

			map[y][x] = '#';
			map[y1][x1] = '#';
			map[y2][x2] = '#';

			//���� ó�� �߰��ϴ� '.'ã�� �ű⿡�� �Լ� ���� �ȴ�.
			int firsty=-1, firstx=0;
			for (int j = 0; j < h; j++)
			{
				for (int k = 0; k < w; k++)
				{
					if (map[j][k] == '.')
					{
						firsty = j;
						firstx = k;
						break;
					}
				}
				if (firsty != -1) break;
			}
			boardcover(firsty, firstx);

			map[y][x] = '.';
			map[y1][x1] = '.';
			map[y2][x2] = '.';
		}
		
	}
	cnt--;

	return;
}

int main()
{
	int k, i, j, C;
	cin >> C;
	for (k = 0; k < C; k++)
	{
		//�ʱ�ȭ
		w = h = ans = cnt_period = cnt = 0;
		for (i = 0; i < 22; i++)
		{
			for (j = 0; j < 22; j++)
			{
				map[i][j] = '\0';
			}
		}

		//�Է�
		cin >> h >> w;
		for (i = 0; i < h; i++) 
		{
			cin >> map[i];
			for (j = 0; j < w; j++)
			{
				if (map[i][j] == '.') cnt_period++;
			}
		}

		//.�� ������ 3�� ��� �ƴϸ� ���� 0
		if (cnt_period % 3 > 0)
		{
			cout << "0\n";
			continue;
		}
		//.�� ������ 0�ϰ�� ���� 1
		if (cnt_period == 0)
		{
			cout << "1\n";
			continue;
		}

		//����
		int firsty = -1, firstx;
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				if (map[i][j] == '.')
				{
					firsty = i;
					firstx = j;
					break;
				}
			}
			if (firsty != -1) break;
		}
		boardcover(firsty, firstx);
		
		cout << ans << '\n';
	}
}