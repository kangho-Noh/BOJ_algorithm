#include <iostream>
#include <cstring>
using namespace std;

int C, N, arr[500], chk[500];

void LIS(int n)
{
	int tmp;
	chk[0] = 1;
	for (int i = 1; i < n; i++)
	{
		tmp = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] > arr[j])
			{
				tmp = max(tmp, chk[j]);
			}
		}
		chk[i] = tmp + 1;
	}
}

int main()
{
	int C; cin >> C;
	for (int ci = 0; ci < C; ci++) {
		memset(arr, 0, sizeof(arr));
		memset(chk, 0, sizeof(chk));
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i];
		LIS(N);
		int ans = 0;
		for (int i = 0; i < N; i++) ans = max(ans, chk[i]);
		cout << ans << '\n';
	}
}