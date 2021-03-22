#include <iostream>
#include <vector>
using namespace std;

vector<int> pre;

void coutPost(int preroot,int left, int right)
{
	if (left >= right) return;
	int root = pre[preroot];
	if (left == right - 1)
	{
		cout << root << '\n';
		return;
	}
	int boundary = right;
	for (int i = left; i < right; i++)
	{
		if (root < pre[i])
		{
			boundary = i;
			break;
		}
	}
	coutPost(preroot + 1, left + 1, boundary);
	coutPost(boundary, boundary, right);
	cout << root << '\n';
}

int main()
{
	int a;
	while (cin >> a)
	{
		pre.push_back(a);
	}
	coutPost(0, 0, pre.size());
}