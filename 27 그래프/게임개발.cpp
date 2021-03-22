#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int buildtime[501], chk[501];
int N, res;
vector<int> pre[501]; //pre[n] n�ǹ��� �������� ���� ���� ������ �ǹ���
queue<int> q, building;
int built[501]; //���ݱ��� ������ �ǹ� üũ

void dfs(int now)
{
	if (chk[now]) return;
	chk[now]++;
	int s = pre[now].size();
	for (int i = 0; i < s; i++)
	{
		dfs(pre[now][i]);
	}
	q.push(now);
	return;
}

int cal_buildtime(int i)
{
	if (!pre[i].size()) return buildtime[i];

	memset(chk, 0, sizeof(chk));
	dfs(i); //�ǹ� ���� ���� ť�� �����
	
	res = 0;
	memset(built, 0, sizeof(built));
	while (!q.empty())
	{
		int now = q.front();
		int maxt = buildtime[now];
		q.pop();
		building.push(now); //58��°�� ��������
		//���ÿ� ���� �� ������ �� �� �ð��� �ɸ��� �ǹ� �ð��� ���Ѵ�
		while (!q.empty())
		{
			now = q.front();
			bool canbuild = true;
			for (int j = 0; j < pre[now].size(); j++)
			{
				if (built[pre[now][j]] == 0) canbuild = false;
			}
			if (canbuild)
			{
				q.pop();
				building.push(now);
				maxt = max(maxt, buildtime[now]);
			}
			else break;
		}
		while (!building.empty())
		{
			built[building.front()]++;
			building.pop();
		}
		res += maxt;
	}
	return res;
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> buildtime[i];
		while (1)
		{
			int a; cin >> a;
			if (a == -1) break;
			pre[i].push_back(a);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << cal_buildtime(i) << '\n';

}