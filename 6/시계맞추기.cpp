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
}; //각 버튼을 누를 경우의 수 = 4의 10제곱 약 100만. (시계라서 4번 누르면 제자리이므로 4번이상 누를 필요가 없으므로) 

void minButtonPress(int cnt, int n) //cnt는 버튼 누른 총 횟수, n은 이제 누를 버튼 
{
	// 기저 사례 : 답을 찾았을 경우
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

	//누르고 재귀
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
			clk[i] = clk[i] / 3 % 4; // 12시 == 0 | 3시 == 1 | 6시 == 2 | 9시 == 3 즉, x%4
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