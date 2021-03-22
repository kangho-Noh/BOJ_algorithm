#include <iostream>
#include <list>
using namespace std;

list<int>::iterator iter;

int main()
{
	int C, N, K;
	cin >> C;
	for (int ci = 0; ci < C; ci++)
	{
		cin >> N >> K;
		list<int> l;
		l.clear();
		for (int i = 1; i <= N; i++)
		{
			l.push_back(i);
		}
		iter = l.begin();
		while (N > 2)
		{
			iter = l.erase(iter);
			N--;
			for (int i = 0; i < K-1; i++)
			{
				if (iter == l.end()) iter = l.begin();
				iter++;
				if (iter == l.end()) iter = l.begin();
			}
		}
		cout << l.front() << ' ' << l.back() << '\n';
	}
}