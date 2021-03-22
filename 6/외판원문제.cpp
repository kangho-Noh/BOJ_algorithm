#include<iostream>
using namespace std;

/*
���ǿ� ����
https://www.acmicpc.net/problem/10971
*/

int N, i, j, ans, cntvisit;
int dist[10][10], visited[10];

void FindMinDistance(int n, int sum,int start) //n�� ���� �ִ� ��, sum�� n���� ����� ��
{
	//���� ���: ��ü ��ȸ�� ������ �� : visited ��� ����, ���ݱ��� �鸰 ���� ���� == N, ���� �ִ� ������ �������� �Ÿ� !=0 �� ���� ���� �� �� �ִ�.
	//���� ���2: ���̻� �� �� �ִ� ���ð� ���µ�, �鸰 ���� �� != N�� ���� ���� �� �� ����, �ٽ� ���ư��� �Ѵ�.
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
	//���� ��ȸ�� ���ð� ���Ҵµ�, �� ���õ� ��� �� �� ������ return
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

	//������ ����
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