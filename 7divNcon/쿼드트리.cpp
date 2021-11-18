#include <iostream>
#include <vector>
using namespace std;

//https://www.acmicpc.net/problem/1992

char map[65][65];
vector<char> ans;

void encodeQuadtree(int N, int starty, int startx) //N�� ���� �� ũ��
{
	//N�� 0�̸� �ٷ� ���� 1�̸� �� ĳ���� �߰��ϰ� ����
	if (N == 0) return;
	char firstchar = map[starty][startx];
	if (N == 1)
	{
		ans.push_back(firstchar);
		return;
	}
	//��� ĭ�� ������ Ȯ��
	bool chk = true;
	for (int i = starty; i < starty + N; i++)
	{
		for (int j = startx; j < startx + N; j++)
		{
			if (firstchar != map[i][j])
			{
				chk = false;
			}
		}
	}
	//�� ������ �� ĳ���� �߰��ϰ� return
	if (chk)
	{
		ans.push_back(firstchar);
		return;
	}
	
	//�ٸ��� �ϳ��� ���� ��� ��ȣ ���� ���� ����. 1234�и� �� Ž���ϸ� ��ȣ �ݱ�.
	ans.push_back('(');
	int half = N / 2;
	encodeQuadtree(half, starty, startx);
	encodeQuadtree(half, starty, startx+ half);
	encodeQuadtree(half, starty+half, startx);
	encodeQuadtree(half, starty+half, startx+half);
	ans.push_back(')');
}

int main()
{
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}
	encodeQuadtree(N, 0, 0);
	for (char i : ans) cout << i;
	cout << '\n';
}