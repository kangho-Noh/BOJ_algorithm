#include <iostream>
#include <string>
using namespace std;


//1234 -> 3412
string reverse(string::iterator & it)
{
	char now = *it;
	++it;

	if (now == 'b' || now == 'w')
	{
		return string(1, now);
	}

	string leftup = reverse(it);
	string rightup = reverse(it);
	string leftdown = reverse(it);
	string rightdown = reverse(it);

	return string(1, 'x') + leftdown + rightdown + leftup + rightup;
}

int main() {
	int C; cin >> C;
	for (int k = 0; k < C; k++)
	{
		string input;
		cin >> input;
		string::iterator it = input.begin();
		string ans = reverse(it);

		cout << ans << '\n';
	}
}