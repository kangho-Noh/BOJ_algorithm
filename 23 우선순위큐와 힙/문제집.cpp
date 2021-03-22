#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> arr[32001]; //arr[n]은 n문제를 풀었을 때 풀 수 있는 문제 벡터
int befcnt[32001]; //befcnt[n] n번 문제가 풀리기 위해 풀려야하는 문제 개수
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
		arr[a].push_back(b); //a를 풀면 풀수 있는 것들 b
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