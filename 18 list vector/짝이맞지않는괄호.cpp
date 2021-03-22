#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack<char> s;
char c[10001];
bool ans;

int main()
{
	int C; cin >> C;
	for (int ci = 0; ci < C; ci++)
	{
		cin >> c;
		while (!s.empty()) s.pop();
		ans = true;
		for (int i = 0; i < strlen(c); i++)
		{
			if (c[i] == '(' || c[i] == '{' || c[i] == '[') s.push(c[i]);
			else
			{
				if (s.empty())
				{
					ans = false;
					break;
				}
				if (c[i] == ')')
				{
					if (s.top() == '(') s.pop();
					else
					{
						ans = false;
						break;
					}
				}
				if (c[i] == '}')
				{
					if (s.top() == '{') s.pop();
					else
					{
						ans = false;
						break;
					}
				}
				if (c[i] == ']')
				{
					if (s.top() == '[') s.pop();
					else
					{
						ans = false;
						break;
					}
				}
			}
		}
		if (ans && s.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
}