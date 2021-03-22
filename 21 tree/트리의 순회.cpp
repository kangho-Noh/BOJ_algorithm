//https://www.acmicpc.net/problem/2263
#include <iostream>
#include <algorithm>
using namespace std;

int post[100001], in[100001], n, i;

//now = post에서 root의 위치 인덱스, left와 right는 현재 사용하는 in의 범위(부분트리)
void coutPre(int now, int left, int right)
{
	if (left >= right) return;
	int root = post[now];
	int ind = find(in + left, in + right, root) - in;
	cout << root << ' ';
	coutPre(now - right + ind, left, ind);
	coutPre(now - 1, ind + 1, right);
}

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n;
	for (i = 0; i < n; i++)	cin >> in[i];
	for (i = 0; i < n; i++)	cin >> post[i];
	coutPre(n - 1, 0, n);
	cout << '\n';
}