#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node
{
	float distance; //float로 한 이유는 구간이 나누어떨어지지 않으면 올림해서 출력해야하기 때문
	int cnt; //구간 나눈 횟수
	Node(float dis, int cnt)
	{
		this->distance = dis;
		this->cnt = cnt;
	}
	bool operator< (const Node& a) const
	{
		return this->distance < a.distance;
	}
};
vector<int> arr;
priority_queue<Node> maxheap;

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int n, m, l; cin >> n >> m >> l;
	arr.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		arr.push_back(a);
	}
	arr.push_back(l);
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size() - 1; i++)
	{
		maxheap.push(Node(arr[i + 1] - arr[i], 1));
	}
	while (m--)
	{
		Node now = maxheap.top();
		maxheap.pop();
		maxheap.push(Node(now.distance * now.cnt / (now.cnt + 1), now.cnt + 1));
	}
	cout << int(ceil(maxheap.top().distance)) << '\n';
	return 0;
}