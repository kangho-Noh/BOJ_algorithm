#include <iostream>
using namespace std;

long long all[101], ans[101];
const int MOD = 1000000007;

int main()
{
	ans[1] = 0;
	ans[2] = 0;
	ans[3] = 2;
	ans[4] = 2;
	all[1] = 1;
	all[2] = 2;
	for (int i = 3; i < 101; i++) all[i] = (all[i - 2] + all[i - 1]) % MOD;
	for (int i = 5; i < 101; i++)
	{
		ans[i] = (ans[i - 2] + ans[i - 4] + (2 * all[i - 3]) % MOD) % MOD;
	}

	int c; cin >> c;
	for (int k = 0; k < c; k++)
	{
		int n; cin >> n;
		cout << ans[n] << '\n';
	}
}