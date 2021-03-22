#include <iostream>
#include <cstring>
using namespace std;

int n;
char c[10];
string s;
string maxans, minans;
int chk[10];
bool found;

void findmax(int now, int cnt)
{
	char nowc = c[cnt];
	char nown = now + '0';
	chk[now] = 1;
	s.push_back(nown); 
	if (cnt == n)
	{
		found = true;
		maxans = s;
		return;
	}
	for (int i = 9; i >= 0; i--)
	{
		if (!chk[i]) 
		{
			if (nowc == '<' && now<i)
			{
				findmax(i, cnt + 1);
			}
			if (nowc == '>' && now>i)
			{
				findmax(i, cnt + 1);
			}
		}
		if (found) return;
	}
	chk[now] = 0;
	s.pop_back();
	return;
}

void findmin(int now, int cnt)
{
	char nowc = c[cnt];
	char nown = now + '0';
	chk[now] = 1;
	s.push_back(nown);
	if (cnt == n)
	{
		found = true;
		minans = s;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (!chk[i])
		{
			if (nowc == '<' && now < i)
			{
				findmin(i, cnt + 1);
			}
			if (nowc == '>' && now > i)
			{
				findmin(i, cnt + 1);
			}
		}
		if (found) return;
	}
	chk[now] = 0;
	s.pop_back();
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	int cnt = 0;
	for (int i = 9; i >= 0; i--)
	{
		findmax(i, cnt);
		if (found) break;
	}
	memset(chk, 0, sizeof(chk));
	cnt = 0;
	found = false;
	s = "";
	for (int i = 0; i < 10; i++)
	{
		findmin(i, cnt);
		if (found) break;
	}
	cout << maxans << '\n' << minans << '\n';
}