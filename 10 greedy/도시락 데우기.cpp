#include <iostream>
#include <algorithm>
using namespace std;

struct dosirak {
	int heat, eat;
	dosirak()
	{
		heat = eat = 0;
	}
	bool operator<(const dosirak& d)
	{
		if (this->eat > d.eat) return true;
		else return false;
	}
};

int N;
dosirak d[10005];

int main()
{
	int c; cin >> c;
	for (int k = 0; k < c; k++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> d[i].heat;
		}
		for (int i = 0; i < N; i++)
		{
			cin >> d[i].eat;
		}
		sort(d, d + N);

		int nowt = 0 , ans = 0;
		for (int i = 0; i < N; i++)
		{
			ans = max(ans, nowt + d[i].heat + d[i].eat);
			nowt = nowt + d[i].heat;
		}
		cout << ans << '\n';
	}
}