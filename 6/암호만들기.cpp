#include<iostream>
#include<vector>
using namespace std;

int L, C, cnt, cntmo, cntja;
char word[15];
vector<char> v;

void swap(int i, int j)
{
	char temp = word[i];
	word[i] = word[j];
	word[j] = temp;
}

void sort(int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (word[i] > word[j])
			{
				swap(i, j);
			}
		}
	}
}

void makePW(int n)
{
	cnt++;
	//암호 개수초과
	if (cnt > L)
	{
		cnt--;
		return;
	}
	//모음자음 파악
	if (word[n] == 'a' || word[n] == 'e' || word[n] == 'i' || word[n] == 'o' || word[n] == 'u')
	{
		cntmo++;
	}
	else
	{
		cntja++;
	}
	v.push_back(word[n]);
	//답일경우
	if (cnt == L) 
	{
		if (cntmo > 0 && cntja > 1)
		{
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i];
			}
			cout << '\n';
		}
	}

	//구현
	for (int i = n+1; i <= cnt + C - L; i++)
	{
		makePW(i);
	}

	if (word[n] == 'a' || word[n] == 'e' || word[n] == 'i' || word[n] == 'o' || word[n] == 'u')
	{
		cntmo--;
	}
	else
	{
		cntja--;
	}
	cnt--;
	v.pop_back();
	return;
}

int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> word[i];
	}
	sort(C);
	
	cnt = cntmo = cntja =0;
	for (int i = 0; i <= C - L; i++)
	{
		makePW(i);
	}
}