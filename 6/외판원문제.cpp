#include<iostream>
using namespace std;

/*
외판원 문제
https://www.acmicpc.net/problem/10971
*/

int N, i, j, ans, cntvisit;
int dist[10][10], visited[10];

void FindMinDistance(int n, int sum,int start) //n은 지금 있는 곳, sum은 n까지 비용의 합
{
	//기저 사례: 전체 순회를 마쳤을 때 : visited 모든 도시, 지금까지 들린 도시 수가 == N, 지금 있는 곳에서 시작지점 거리 !=0 일 때가 답이 될 수 있다.
	//기저 사례2: 더이상 갈 수 있는 도시가 없는데, 들린 도시 수 != N일 때는 답이 될 수 없고, 다시 돌아가야 한다.
	visited[n] = 1;
	cntvisit++;
	if (cntvisit==N)
	{
		int min = sum + dist[n][start];
		if(ans>min&&dist[n][start]!=0) ans = min;
		cntvisit--;
		visited[n] = 0;
		return;
	}
	//아직 순회할 도시가 남았는데, 그 도시들 모두 갈 수 없으면 return
	bool con = false;
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 0 && dist[n][i] != 0) con = true;
	}
	if (!con)
	{
		cntvisit--;
		visited[n] = 0;
		return;
	}

	//나머지 구현
	for (int i = 0; i < N; i++)
	{
		if (dist[n][i] > 0 && visited[i]==0)
		{
			FindMinDistance(i, dist[n][i] + sum, start);
		}
	}

	visited[n] = 0;
	cntvisit--;
	return;
}

int main()
{
	ans = 987654321;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> dist[i][j];
		}
	}
	for (i = 0; i < N; i++)
	{
		cntvisit = 0;
		FindMinDistance(i, 0, i);
	}
	cout << ans << '\n';
}