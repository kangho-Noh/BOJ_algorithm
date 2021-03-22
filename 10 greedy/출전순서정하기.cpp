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
			sort(rating[i], rating[i] + N); //각 나라별 레이팅 오름차순 정렬
		}
		ans = 0;
		int tmp = 0; //한국선수 인덱스
		for (int i = 0; i < N; i++) //i는 러시아 선수 인덱스
		{
			for (int j = tmp; j < N; j++) //j는 한국 선수 인덱스
			{
				if (rating[0][i] <= rating[1][j]) //한국선수 레이팅이 같거나 높을경우 이김
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