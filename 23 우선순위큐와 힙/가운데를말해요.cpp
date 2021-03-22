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
		if (i % 2) //������ ���� Ȧ��(��, min, max ũ�� ����)
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
		else //������ ���� ¦��(minheap�� maxheap���� 1��ŭ)
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