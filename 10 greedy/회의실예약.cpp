//https://www.acmicpc.net/problem/1931
#include <iostream>
#include <algorithm>
using namespace std;

struct times {
	int start, end;

	times()
	{
		start = end = 0;
	}

	bool operator<(times& t)
	{
		if (this->end < t.end) return true;
		else if (this->end == t.end)
		{
			if (this->start < t.start) return true;
			else return false;
		}
		return false;
	}
};

int N, ans;
times t[100001];

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int c; cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> t[i].start >> t[i].end;
	}
	sort(t, t+c);
	ans = 1;
	int end = t[0].end;
	int start;
	for (int i = 1; i < c; i++)
	{
		start = t[i].start;
		if (start >= end)
		{
			ans++;
			end = t[i].end;
		}
	}
	cout << ans << '\n';
}
