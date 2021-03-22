//https://www.acmicpc.net/problem/1991
#include <iostream>
#include <cstring>
using namespace std;

int Tree[27][2], root; //[n][0] = left, [n][1] = right

void Pre(int now) {
	cout << char(now + 'A');
	if (Tree[now][0] != -1) Pre(Tree[now][0]);
	if (Tree[now][1] != -1) Pre(Tree[now][1]);
	if (root == now) cout << '\n';
}
void In(int now) {
	if (Tree[now][0] != -1) In(Tree[now][0]);
	cout << char(now + 'A');
	if (Tree[now][1] != -1) In(Tree[now][1]);
	if (root == now) cout << '\n';
}
void Post(int now) {
	if (Tree[now][0] != -1) Post(Tree[now][0]);
	if (Tree[now][1] != -1) Post(Tree[now][1]);
	cout << char(now + 'A');
	if (root == now) cout << '\n';
}

int main()
{
	int N; cin >> N;
	memset(Tree, -1, sizeof(Tree));
	for (int i = 0; i < N; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		if (i == 0) root = a - 'A';
		if (b != '.') Tree[a - 'A'][0] = b - 'A';
		if (c != '.') Tree[a - 'A'][1] = c - 'A';
	}
	Pre(root);
	In(root);
	Post(root);
}