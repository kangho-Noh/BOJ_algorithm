#include <iostream>
#include <algorithm>
using namespace std;

int N, rating[2][105],ans;

int main()
{
	int C; cin >> C;
	for (int ci = 0; ci < C; ci++)
	{
		cin >> N;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> rating[i][j];
			}
			sort(rating[i], rating[i] + N); //�� ���� ������ �������� ����
		}
		ans = 0;
		int tmp = 0; //�ѱ����� �ε���
		for (int i = 0; i < N; i++) //i�� ���þ� ���� �ε���
		{
			for (int j = tmp; j < N; j++) //j�� �ѱ� ���� �ε���
			{
				if (rating[0][i] <= rating[1][j]) //�ѱ����� �������� ���ų� ������� �̱�
				{
					ans++;
					tmp = j + 1;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}