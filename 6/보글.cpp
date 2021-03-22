#include<iostream>
#include<string.h>
using namespace std;

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int C, N;
//map�� 5x5 ��, word�� ã�ƾ��� �ܾ� ���
char map[7][7], word[11][11];
bool found, fo;

//n = ���° �������� (w[n]�� ã�ƾ��� �ܾ�, w�� ����)
bool canFind(int y,int x, int n, const char* w)
{
	if (n == int(strlen(w))) return true;

	//w[n]�� ã�� ����
	for (int i = 0; i < 8; i++)
	{
		if (y + dy[i] >= 0 && x + dx[i] >= 0)
		{
			if (map[y + dy[i]][x + dx[i]] == w[n])
			{
				if(canFind(y + dy[i], x + dx[i], n + 1, w)) return true;
			}
		}
	}
	return false;
}


int main() {
	cin.sync_with_stdio(false);
	cin >> C;
	for (int k = 0; k < C; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			cin >> map[i];
		}

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> word[i];
			found = false;
			for (int j = 0; j < strlen(word[i]); j++)
			{
				fo = false;
				for (int w = 0; w < 5; w++)
				{
					for (int z = 0; z < 5; z++)
					{
						if (map[w][z] == word[i][j]) fo = true;
					}
				}
				if (!fo) 
					break;
			}
			if (fo)
			{
				for (int j = 0; j < 5; j++)
				{
					for (int w = 0; w < 5; w++)
					{
						if(canFind(j,w, 0, word[i])) found = true;
					}
				}
			}
			if (found) cout << word[i] << ' ' << "YES\n";
			else cout << word[i] << ' ' << "NO\n";
		}
	}
}