#include <iostream>
using namespace std;

int ans;
int clk[16], button_pressed[10];
int button[10][16] =
{
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0}, //0 1 2
	{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0}, //3 7divNcon 9 11
	{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1}, //4 10 14 15
	{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0}, //0 4 5 6 7divNcon
	{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0}, //6 7divNcon 8dp 10 12
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1}, //0 2 14 15
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1}, //3 14 15
	{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1}, //4 5 7divNcon 14 15
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0}, //1 2 3 4 5
	{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0} //3 4 5 9 13
}; //�� ��ư�� ���� ����� �� = 4�� 10���� �� 100��. (�ð�� 4�� ������ ���ڸ��̹Ƿ� 4���̻� ���� �ʿ䰡 �����Ƿ�) 

void minButtonPress(int cnt, int n) //cnt�� ��ư ���� �� Ƚ��, n�� ���� ���� ��ư 
{
	// ���� ��� : ���� ã���� ���
	int chk_ans = 1;
	for (int i = 0; i < 16; i++)
	{
		if (clk[i] != 0) chk_ans = 0;
	}
	if (chk_ans)
	{
		if(ans > cnt) ans = cnt;
		return;
	}

	//������ ���
	button_pressed[n]++;
	for (int i = 0; i < 16; i++)
	{
		clk[i] = (clk[i] + button[n][i]) % 4;
	}
	for (int i = n; i < 10; i++)
	{
		if (button_pressed[i] < 4)
			minButtonPress(cnt + 1, i);
	}
	for (int i = 0; i < 16; i++)
	{
		clk[i] = (clk[i] + 3 * button[n][i]) % 4;
	}
	button_pressed[n]--;
	return;
}

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int C;
	cin >> C;
	for (int z = 0; z < C; z++)
	{
		ans = 987654321;
		for (int i = 0; i < 10; i++)
		{
			button_pressed[i] = 0;
		}
		for (int i = 0; i < 16; i++)
		{
			cin >> clk[i];
			clk[i] = clk[i] / 3 % 4; // 12�� == 0 | 3�� == 1 | 6�� == 2 | 9�� == 3 ��, x%4
		}

		for (int i = 0; i < 10; i++)
		{
			minButtonPress(0, i);
		}

		if (ans == 987654321)
		{
			cout << -1 << '\n';
		}
		else cout << ans << '\n';
	}
}