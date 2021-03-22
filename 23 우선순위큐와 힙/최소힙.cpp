#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int> > minheap;

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int inp; cin >> inp;
		if (inp == 0)
		{
			if (minheap.empty()) cout << 0 << '\n';
			else
			{
				cout << minheap.top()<<'\n';
				minheap.pop();
			}
		}
		else
		{
			minheap.push(inp);
		}
	}
}