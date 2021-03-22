#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > minheap;
priority_queue<int, vector<int>, less<int> > maxheap;
vector<int> arr;

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		arr.clear();
		while (!minheap.empty()) minheap.pop();
		while (!maxheap.empty()) maxheap.pop();
		int a, n; cin >> n; 
		cout << n / 2 + 1 << '\n';
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			arr.push_back(a);
		}
		int median = arr[0];
		cout << median << ' ';
		int prcnt = 1;
		for (int i = 1; i < n; i++)
		{
			if (prcnt == 10)
			{
				cout << '\n';
				prcnt = 0;
			}
			int now = arr[i];
			if (i % 2)
			{
				if (now >= median)
				{
					minheap.push(now);
				}
				else
				{
					minheap.push(median);
					if (i == 1)
					{
						median = now;
					}
					else
					{
						if (now < maxheap.top())
						{
							median = maxheap.top();
							maxheap.pop();
							maxheap.push(now);
						}
						else
						{
							median = now;
						}
					}
				}
			}
			else //Ãâ·Â
			{
				if (now <= median)
				{
					maxheap.push(now);
				}
				else
				{
					maxheap.push(median);
					if (now < minheap.top())
					{
						median = now;
					}
					else
					{
						median = minheap.top();
						minheap.pop();
						minheap.push(now);
					}
				}
				cout << median << ' ';
				prcnt++;
			}
		}
		cout << '\n';
	}
}