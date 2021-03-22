#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, K, C;
	cin >> C;
	for (int ci = 0; ci < C; ci++)
	{
		cin >> N >> K;
		queue<int> q;
		for (int i = 1; i <= N; i++)
			q.push(i);
		while (q.size() > 2)
		{
			q.pop();
			for (int i = 0; i < K-1; i++)
			{
				q.push(q.front());
				q.pop();
			}
		}
		cout << min(q.front(), q.back()) << ' ' << max(q.front(), q.back()) << '\n';
	}
}