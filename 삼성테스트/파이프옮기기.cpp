//https://www.acmicpc.net/problem/17070
#include <iostream>
using namespace std;

int map[18][18], dae[18][18], sae[18][18], ga[18][18];

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	ga[1][2]++;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 3; j <= n; j++)
		{
			if (map[i][j] == 1) continue;

			ga[i][j] += ga[i][j - 1] + dae[i][j - 1];

			sae[i][j] += sae[i - 1][j] + dae[i - 1][j];

			//º®
			if (map[i - 1][j] != 1 && map[i][j - 1] != 1)
				dae[i][j] += ga[i - 1][j - 1] + sae[i - 1][j - 1] + dae[i - 1][j - 1];
		}
	}
	cout << ga[n][n] + sae[n][n] + dae[n][n] << '\n';
}