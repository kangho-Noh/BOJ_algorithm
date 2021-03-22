//https://www.acmicpc.net/problem/2447
#include <iostream>
using namespace std;

char map[2200][2200];

void star10(int N, int y, int x)
{
	if (N == 1) 
	{
		map[y][x] = '*';
		return;
	}
	for (int i = 0; i < N; i += N / 3)
	{
		for (int j = 0; j < N; j += N / 3)
		{
			if (i==N/3 && j == N/3) {}
			else star10(N / 3, y+i, x+j);
		}
	}
}

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j] = ' ';
		}
	}
	star10(N, 0, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}