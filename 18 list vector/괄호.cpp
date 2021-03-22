#include <iostream>
using namespace std;

int main()
{
	string s; int cnt, i, t, u; cin >> t;
	for (u = 0; u < t; u++)
	{
		cnt = 0; cin >> s;
		for (i = 0; i < s.size(); i++)
		{
			if (s[i] == '(') cnt++;
			if (s[i] == ')')
			{
				cnt--;
				if (cnt < 0) break;
			}
		}
		if (cnt == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}