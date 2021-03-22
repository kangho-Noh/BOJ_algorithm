#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
	int num;
	int jul;
	node(int n, int j)
	{
		num = n;
		jul = j;
	}
	bool operator< (const node& o) const
	{
		if (this->jul > o.jul) return true;
		else if (this->jul == o.jul)
		{
			if (this->num > o.num) return true;
		}
		else
		{
			return false;
		}
		return false;
	}
};
priority_queue<node> minheap;

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
				cout << minheap.top().num << '\n';
				minheap.pop();
			}
		}
		else
		{
			minheap.push(node(inp,abs(inp)));
		}
	}
}