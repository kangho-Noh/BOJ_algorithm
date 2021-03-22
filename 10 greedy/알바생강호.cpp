#include <iostream>
#include <algorithm>
using namespace std;

long long tip[100000], N, ans;

bool cmp(long long a, long long b)
{
	return a > b;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> tip[i];
	sort(tip, tip + N, cmp);
	int nowtip;
	for (int i = 0; i < N; i++)
	{
		nowtip = tip[i] - i;
		if (nowtip < 0) break;
		ans += nowtip;
	}
	cout << ans << '\n';
}