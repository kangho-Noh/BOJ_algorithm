#include <iostream>
#include <cmath>
using namespace std;

int n, m;
double dp[1010][2010]; //dp[x][y] == x�Ͽ� y���Ϳ� ������ Ȯ��

int main()
{
	cout << fixed;
	cout.precision(10);
	cin.tie(NULL);
	cin.sync_with_stdio(false); 
	
	dp[1][1] = 0.25;
	dp[1][2] = 0.75;
	for (int i = 1; i < 1000; i++)
	{
		for (int j = i; j < i * 2 + 1; j++)
		{
			if (dp[i][j] != 0)
			{
				dp[i + 1][j + 1] += dp[i][j] * 0.25; //������ �� �ȿͼ� 1m �������
				dp[i + 1][j + 2] += dp[i][j] * 0.75; //������ �� �ͼ� 2m �������
			}
		}
	}
	int c; cin >> c;
	for (int k = 0; k < c; k++)
	{
		cin >> n >> m;
		double ans = 0;
		for (int i = n; i < 2 * m + 1; i++) ans += dp[m][i];
		cout << ans << '\n';
	}
}