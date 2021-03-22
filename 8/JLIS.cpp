#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

const long long NEGINF = -3000000000;
int n, m, a1[101], a2[101];
int chk[101][101];

int JLIS(int a, int b)
{
	int& ret = chk[a + 1][b + 1];
	if (ret != -1) return ret;
	ret = 0;
	long long aa = (a == -1 ? NEGINF : a1[a]);
	long long bb = (b == -1 ? NEGINF : a2[b]);
	long long maxElement = max(aa, bb);

	for (int na = a + 1; na < n; na++)
	{
		if (maxElement < a1[na])
		{
			ret = max(ret, JLIS(na, b) + 1);
		}
	}
	for (int nb = b + 1; nb < m; nb++)
	{
		if (maxElement < a2[nb])
		{
			ret = max(ret, JLIS(a, nb) + 1);
		}
	}
	return ret;
}

int main()
{
	int c; cin >> c;
	for (int k = 0; k < c; k++)
	{
		cin >> n >> m;
		memset(chk, -1, sizeof(chk));
		for (int i = 0; i < n; i++) cin >> a1[i];
		for (int i = 0; i < m; i++) cin >> a2[i];
		cout << JLIS(-1, -1) << '\n';
	}
}