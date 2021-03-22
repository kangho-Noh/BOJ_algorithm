#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> arr[32001]; //arr[n]�� n������ Ǯ���� �� Ǯ �� �ִ� ���� ����
int befcnt[32001]; //befcnt[n] n�� ������ Ǯ���� ���� Ǯ�����ϴ� ���� ����
priority_queue<int, vector<int>, greater<int> > minheap;
int chk[32001];

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(0);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) minheap.push(i);
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		arr[a].push_back(b); //a�� Ǯ�� Ǯ�� �ִ� �͵� b
		befcnt[b]++;
	}
	while (!minheap.empty())
	{
		int now = minheap.top();
		minheap.pop();

		if (befcnt[now] == 0 && chk[now] == 0)
		{
			cout << now << ' ';
			chk[now]++;
			int s = arr[now].size();
			for (int i = 0; i < s; i++)
			{
				befcnt[arr[now][i]]--;
				if(befcnt[arr[now][i]] == 0)
					minheap.push(arr[now][i]);
			}
		}
	}
	cout << '\n';
}