#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > minHeap;
priority_queue<int, vector<int>, less<int> > maxHeap;

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n, now;
	cin >> n;
	int median;
	cin >> now;
	median = now;
	cout << median << '\n';
	for (int i = 1; i < n; i++)
	{
		cin >> now;
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
					cout << median << '\n';
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
		cout << median << '\n';
	}
}