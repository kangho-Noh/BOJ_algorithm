//https://www.acmicpc.net/problem/2164
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n; cin >> n;
	queue<int> q;
	for (int i = 0; i < n; i++) q.push(i + 1);
	int tmp, cnt=0;
	while (!q.empty())
	{
		if (!cnt)
		{
			tmp = q.front();
			q.pop();
			cnt++;
		}
		else
		{
			tmp = q.front();
			q.pop();
			q.push(tmp);
			cnt--;
		}
	}
	cout << tmp << '\n';
}