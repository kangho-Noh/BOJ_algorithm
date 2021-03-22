#include <iostream>
#include <cstring>
using namespace std;

int N, arr[1001], chk[1001];

int LIS(int n)
{
	if (chk[n] != -1) return chk[n];
	int& ret = chk[n];
	ret = 1;
	for (int i = n + 1; i < N; i++)
	{
		if(arr[n] < arr[i])
			ret = max(ret, LIS(i) + 1);
	}
	return ret;
}

int main()
{
	cin >> N;
	memset(chk, -1, sizeof(chk));
	for (int i = 0; i < N; i++) cin >> arr[i];
	int maxLen = 0;
	for (int i = 0; i < N; i++)
	{
		maxLen = max(maxLen, LIS(i));
	}
	cout << maxLen << '\n';
}