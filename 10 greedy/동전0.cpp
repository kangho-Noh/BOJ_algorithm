#include <iostream>
using namespace std;

int N, K, coin[10], ans;

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> coin[i];
	for (int i = N - 1; i >= 0; i--)
	{
		if (coin[i] <= K)
		{
			ans += K / coin[i];
			K %= coin[i];
			if (!K) break;
		}
	}
	cout << ans << '\n';
}