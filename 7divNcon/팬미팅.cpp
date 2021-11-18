#include <iostream>
#include <string>
using namespace std;

string member, fan;
int memnum, fannum, ans;

void fanmeeting(int l, int r)
{
	if (r <= l) return;

	int half = (l + r) / 2;

	//멤버가 M일 때 처음 사람 성별 다르면 답 가능성 있음 F일땐 항상 답 가능성 있음
	if (member[0] == 'M' &&  fan[half] == 'M') {}
	else
	{
		bool isAns = true;
		for (int i = 0; i < memnum; i++)
		{
			if (member[i]=='M' && member[i] == fan[half + i]) {
				isAns = false;
				break;
			}
		}
		if (isAns) ans++;
	}

	//왼쪽 오른쪽 모두 탐색
	fanmeeting(l, half);
	fanmeeting(half+1, r);
	return;
}

int main()
{
	int C; cin >> C;
	for (int k = 0; k < C; k++)
	{
		cin >> member >> fan;
		memnum = member.size();
		fannum = fan.size();
		ans = 0;
		fanmeeting(0, fannum-memnum+1);
		cout << ans << '\n';
	}
}