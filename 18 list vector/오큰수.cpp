#include <iostream>
#include <stack>
using namespace std;

int arr[1000000], ans[1000000];
stack<int> s;

int main()
{
	cin.tie(0); cin.sync_with_stdio(false);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	ans[N - 1] = -1;
	s.push(arr[N - 1]);
	for (int i = N - 2; i >= 0; i--)
	{
		if (arr[i] < arr[i + 1]) ans[i] = arr[i + 1];
		else if (arr[i] < ans[i + 1]) ans[i] = ans[i + 1];
		else
		{
			while (!s.empty() && arr[i] >= s.top())
			{
				s.pop();
			}
			if (s.empty()) ans[i] = -1;
			else
			{
				ans[i] = s.top();
			}
		}
		s.push(arr[i]);
	}
	for (int i = 0; i < N - 1; i++) cout << ans[i] << ' ';
	cout << ans[N - 1] << '\n';
}