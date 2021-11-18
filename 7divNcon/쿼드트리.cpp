#include <iostream>
#include <vector>
using namespace std;

//https://www.acmicpc.net/problem/1992

char map[65][65];
vector<char> ans;

void encodeQuadtree(int N, int starty, int startx) //N은 현재 맵 크기
{
	//N이 0이면 바로 리턴 1이면 그 캐릭터 추가하고 리턴
	if (N == 0) return;
	char firstchar = map[starty][startx];
	if (N == 1)
	{
		ans.push_back(firstchar);
		return;
	}
	//모든 칸이 같은지 확인
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
	//다 같으면 그 캐릭터 추가하고 return
	if (chk)
	{
		ans.push_back(firstchar);
		return;
	}
	
	//다른게 하나라도 있을 경우 괄호 열고 분할 시작. 1234분면 다 탐색하면 괄호 닫기.
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