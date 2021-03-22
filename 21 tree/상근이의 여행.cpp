//https://www.acmicpc.net/problem/9372
#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		//ÃÊ±âÈ­
		int a, b, N, M;
		cin >> N >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
		}
		cout << N-1 << '\n';
	}
}