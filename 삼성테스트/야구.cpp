//https://www.acmicpc.net/problem/17281
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int player[50][9]; //0�� ������ �׻� 4��Ÿ�� | Ÿ�� ���� ����� ���� 8! = 40320 | �ִ� ���� �� : �� �̴� 1�� �ƿ� (27Ÿ��) * �ִ� �̴׼� 50 = 1350
//�����ϰ� Ǯ�� => ����� �� ��� ���ϰ� �� ��츶�� ��� �̴� �������� ���� ū �� �����ϴ� ����Լ�
vector<int> order;
int n, chk[9], cnt, ans;

void playball(int now) 
{
	order.push_back(now);
	cnt++;
	chk[now]++;
	if (cnt == 9)
	{
		//��� �̴� ��������
		queue<int> ru;
		for (int i = 0; i < 3; i++) ru.push(0);
		int out = 0, nowhit = 0, score = 0;
		for (int i = 0; i < n; i++)
		{
			while (out < 3)
			{
				if (nowhit > 8) nowhit %= 9;
				int result = player[i][order[nowhit++]];
				if (result == 0)
				{
					out++;
				}
				else if (result == 1)
				{
					score += ru.front();
					ru.pop();
					ru.push(1);
				}
				else if (result == 2)
				{
					score += ru.front();
					ru.pop();
					ru.push(1);
					score += ru.front();
					ru.pop();
					ru.push(0);
				}
				else if (result == 3)
				{
					score += ru.front();
					ru.pop();
					ru.push(1);
					score += ru.front();
					ru.pop();
					ru.push(0);
					score += ru.front();
					ru.pop();
					ru.push(0);
				}
				else
				{
					score += ru.front();
					ru.pop();
					ru.push(1);
					score += ru.front();
					ru.pop();
					ru.push(0);
					score += ru.front();
					ru.pop();
					ru.push(0);
					score += ru.front();
					ru.pop();
					ru.push(0);
				}
			}
			out = 0;
		}
		ans = max(ans, score);
		order.pop_back();
		cnt--;
		chk[now]--;
		return;
	}

	for (int i = 0; i < 9; i++)
	{
		if (chk[i] == 0)
		{
			playball(i);
		}
	}
	order.pop_back();
	cnt--;
	chk[now]--;
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> player[i][j];
		}
	}
	for (int i = 1; i < 9; i++)
	{
		playball(i);
	}
	cout << ans << '\n';
}