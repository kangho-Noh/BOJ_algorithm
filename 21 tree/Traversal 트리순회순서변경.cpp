#include <iostream>
using namespace std;

int pre[100], in[100];
int cnt, n;

void coutPost(int left, int right)
{
	if (left >= right)
	{
		cnt--;
		return;
	}
	int root = pre[cnt];
	int ind = 0; // in에서 찾은 ind
	for (int i = 0; i < n; i++)
	{
		if (root == in[i]) ind = i;
	}
	cnt++;
	coutPost(left, ind);
	cnt++;
	coutPost(ind + 1, right);
	cout << root << ' ';
	return;
}

int main()
{
	int C; cin >> C;
	for (int ci = 0; ci < C; ci++)
	{
		cnt = 0;
		int a; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> pre[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> in[i];
		}
		coutPost(0, n);
		cout << '\n';
	}
}