#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int> > minheap;

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(0);
	int a, i, N; cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> a;
		minheap.push(a);
	}
	if (N == 1)
	{
		cout << 0 << '\n';
		return 0;
	}
	while (!minheap.top()) minheap.pop();
	int ans = 0;
	while (!minheap.empty())
	{
		if (minheap.size() == 1)
		{
			ans += minheap.top();
			minheap.pop();
		}
		else
		{
			a = minheap.top();
			minheap.pop();
			a += minheap.top();
			minheap.pop();
			ans += a;
			if (minheap.empty()) break;
			minheap.push(a);
		}
	}
	cout << ans << '\n';
}