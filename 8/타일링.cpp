#include <iostream>
using namespace std;

long long ans[105];


int main()
{
	int c; cin >> c;
	for (int k = 0; k < c; k++)
	{
		ans[1] = 1;
		ans[2] = 2;
		ans[3] = 3;
		for (int i = 4; i <= 100; i++)
		{
			ans[i] = (ans[i - 1] + ans[i - 2]) % 1000000007;
		}
		int n; cin >> n;
		cout << ans[n] << '\n';
	}
}