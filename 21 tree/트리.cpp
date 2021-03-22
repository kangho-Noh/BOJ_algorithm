//https://www.acmicpc.net/problem/4256
#include <iostream>
#include <cstring>
using namespace std;

int N, pre[1001], in[1001], cnt;

void coutPost(int left, int right)
{
	if (right <= left)
	{
		cnt--;
		return;
	}
	int root = pre[cnt];
	int boundary = -1;
	for (int i = 0; i < N; i++)
	{
		if (root == in[i])
		{
			boundary = i;
			break;
		}
	}
	cnt++;
	coutPost(left, boundary);
	cnt++;
	coutPost(boundary+1, right);
	cout << root << ' ';
	return;
}

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		memset(pre, 0, sizeof(pre));
		memset(in, 0, sizeof(in));
		cnt = 0;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> pre[i];
		for (int i = 0; i < N; i++) cin >> in[i];
		coutPost(0, N);
		cout << '\n';
	}
}