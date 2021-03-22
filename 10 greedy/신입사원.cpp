#include <iostream>
#include <algorithm>
using namespace std;

struct newbie
{
	int doc, talk;
	bool operator<(const newbie& n)
	{
		return this->doc < n.doc;
	}
};

int N;
newbie worker[100000];

int main()
{
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> worker[i].doc >> worker[i].talk;
		}
		sort(worker, worker + N);
		int m = worker[0].talk, ans = 1;
		for (int i = 1; i < N; i++)
		{
			if (worker[i].talk < m)
			{
				ans++;
				m = worker[i].talk;
			}
		}
		cout << ans << '\n';
	}
}