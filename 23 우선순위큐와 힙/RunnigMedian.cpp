#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > minHeap;
priority_queue<int, vector<int>, less<int> > maxHeap;


int main()
{
	int C; cin >> C;
	for (int ci = 0; ci < C; ci++)
	{
		int n, a, b;
		cin >> n >> a >> b;
		long long median = 1983, pre = 1983;
		long long now;
		long long ans = 1983;
		for (int i = 1; i < n; i++)
		{
			now = (pre * a + b) % 20090711;
			pre = now;
			if (i % 2) //수열의 길이 홀수(즉, min, max 크기 같음)
			{
				if (now >= median)
				{
					minHeap.push(now);
				}
				else
				{
					if (i == 1)
					{
						minHeap.push(median);
						median = now;
						ans += median;
						continue;
					}
					minHeap.push(median);
					if (maxHeap.top() > now)
					{
						median = maxHeap.top();
						maxHeap.pop();
						maxHeap.push(now);
					}
					else
					{
						median = now;
					}
				}
			}
			else //수열의 길이 짝수(minheap이 maxheap보다 1더큼)
			{
				if (now <= median)
				{
					maxHeap.push(now);
				}
				else
				{
					maxHeap.push(median);
					if (now > minHeap.top())
					{
						median = minHeap.top();
						minHeap.pop();
						minHeap.push(now);
					}
					else
					{
						median = now;
					}
				}
			}
			ans += median;
			ans %= 20090711;
		}
		while (!minHeap.empty())
		{
			minHeap.pop();
		}
		while (!maxHeap.empty())
		{
			maxHeap.pop();
		}
		cout << ans << '\n';
	}
}