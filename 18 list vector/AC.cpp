//https://www.acmicpc.net/problem/5430
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	cin.tie(0); cin.sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		deque<string> d;
		string cmd; cin >> cmd;
		int len; cin >> len;
		string arr; cin >> arr;
		string a=""; int ind=1;
		for (int i = 0; i < len; i++)
		{
			while (arr[ind] != ',' && arr[ind] !=']')
			{
				a += arr[ind];
				ind++;
			}
			d.push_back(a);
			a = "";
			ind++;
		}
		bool dir = true, err= false;
		for (int i = 0; i < cmd.size(); i++)
		{
			if (cmd[i] == 'R') dir = !dir;
			else
			{
				if (d.empty()) 
				{
					err = true; 
					break;
				}
				else if (dir)
				{
					d.pop_front();
				}
				else
				{
					d.pop_back();
				}
			}
		}
		if (err) cout << "error\n";
		else
		{
			cout << '[';
			if(dir)
				while (!d.empty())
				{
					cout << d.front();
					d.pop_front();
					if (!d.empty()) cout << ',';
				}
			else
				while (!d.empty())
				{
					cout << d.back();
					d.pop_back();
					if (!d.empty()) cout << ',';
				}
			cout << "]\n";
		}
	}
}