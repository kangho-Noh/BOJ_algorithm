// https://www.acmicpc.net/problem/1068
#include <iostream>
#include <vector>
using namespace std;

int root, cnt, deletenode;
vector<int> child[50]; //child[n] : n의 자식 모음 if(child[n].empty()) leafnode

void countLeafNode(int now)
{
	if (now == deletenode) return;
	if (child[now].empty())
	{
		cnt++;
		return;
	}
	int s = child[now].size();
	if (s == 1 && child[now][0] == deletenode)
	{
		cnt++; return;
	}
	for (int i = 0; i < s; i++)
	{
		countLeafNode(child[now][i]);
	}
}

int main()
{
	int n, a; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == -1) root = i;
		else child[a].push_back(i);
	}
	cin >> deletenode;
	countLeafNode(root);
	cout << cnt << '\n';
}