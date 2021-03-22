#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int N;
vector<string> v;
int order[26][26]; //order[a][b] = 1이면 a->b
bool inv;
int seen[26]; //dfs 함수 한번 거치면 1
stack<char> ans;

void make_dict()
{
	for (int i = 0; i < N - 1; i++)
	{
		int len = min(v[i].size(), v[i + 1].size());
		for (int j = 0; j < len; j++)
		{
			int a = v[i][j] - 'a';
			int b = v[i + 1][j] - 'a';
			if (a!=b)
			{
				order[a][b] = 1;
				if (order[b][a] == 1) inv = true;
				break;
			}
		}
	}
}

void dfs(int now)
{
	if (seen[now]) return;
	seen[now]++;
	for (int i = 0; i < 26; i++)
	{
		if (order[now][i]) 
			dfs(i);
	}
	ans.push(now);
}

void dfsall()
{
	for (int i = 0; i < 26; i++)
	{
		dfs(i);
	}
	while (!ans.empty())
	{
		cout << char(ans.top() + 'a');
		ans.pop();
	}
	cout << '\n';
	return;
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(false);
	int C; cin >> C;
	for (int ci = 0; ci < C; ci++)
	{
		inv = false;
		v.clear();
		memset(order, 0, sizeof(order));
		memset(seen, 0, sizeof(seen));
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			string s; cin >> s;
			v.push_back(s);
		}
		make_dict();
		if (inv) cout << "INVALID HYPOTHESIS\n";
		else dfsall();
	}
}