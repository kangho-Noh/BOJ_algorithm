#include <iostream>
#include <cmath>
using namespace std;

int n, m;
double dp[1010][2010]; //dp[x][y] == x일에 y미터에 도달할 확률

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
				dp[i + 1][j + 1] += dp[i][j] * 0.25; //다음날 비가 안와서 1m 오를경우
				dp[i + 1][j + 2] += dp[i][j] * 0.75; //다음날 비가 와서 2m 오를경우
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