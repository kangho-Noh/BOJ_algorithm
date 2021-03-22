#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int arr[10005], chk[10005], length;

int chkdiff(int start, int l)
{
	int end = start + l;
	//난이도 파악
	int diff = 10;
	bool d1 = true;
	for (int i = start; i < end-1; i++)
	{
		if (arr[i] != arr[i + 1]) d1 = false;
	}
	if (d1) return 1;

	int cha = arr[start + 1] - arr[start];
	bool samecha = true;
	for (int i = start; i < end - 1; i++)
	{
		if (cha != arr[i + 1] - arr[i]) samecha = false;
	}
	if (samecha)
	{
		if (abs(cha) == 1) return 2;
		else return 5;
	}

	bool watdagatda = false;
	if (l == 3 && arr[start] == arr[start + 2]) watdagatda = true;
	else if(l==4&&arr[start] == arr[start + 2] && arr[start+1] == arr[start+3])watdagatda = true;
	else if(l==5&& arr[start] == arr[start + 2] && arr[start + 1] == arr[start + 3] && arr[start] == arr[start + 4])watdagatda = true;
	if (watdagatda) return 4;

	return 10;
}

int PI(int start)
{
	//기저사례: 범위
	if (start == length) return 0;
	//기저사례: 캐시
	if (chk[start] != 0) return chk[start];

	chk[start] = 987654321;
	for (int i = 3; i < 6; i++)
	{
		if(start + i <= length)
			chk[start] = min(chk[start], PI(start + i) + chkdiff(start, i));
	}
	return chk[start];
}

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int c; cin >> c;
	for (int k = 0; k < c; k++)
	{
		string s;
		memset(chk, 0, sizeof(chk));
		memset(arr, 0, sizeof(arr));
		cin >> s;
		length = s.length();
		for (int i = 0; i < length; i++)
		{
			arr[i] = s[i]-'0';
		}
		cout << PI(0) << '\n';
	}
}