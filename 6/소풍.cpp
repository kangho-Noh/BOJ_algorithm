#include <iostream>
using namespace std;

int C, n, m, cnt, ans;
int chk[10], fr[10][10]; //chk는 짝이 안지어진 학생은 0 지어지면 1, fr은 짝인 친구면 fr[i][j] == 1 

void chkfriend(int a, int b)
{
	
	//친구가 아니라면 return
	if (fr[a][b] != 1) return;
	//이미 짝이 지어진 학생이라면 return
	if (chk[a] == 1 || chk[b] == 1) return;
	
	//구현
	chk[a] = chk[b] = 1;
	cnt++;
	//모든 학생이 짝이 지어졌다면 ans++
	if (cnt == n / 2)
	{
		ans++;
		cnt--;
		chk[a] = chk[b] = 0;
		return;
	}
	//아직 짝이 남았다면 재귀함수
	for (int i = a + 1; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			chkfriend(i,j);
		}
	}
	//구현이 다 끝나면 초기화 후 리턴
	chk[a] = chk[b] = 0;
	cnt--;
	return;
}

int main() {
	cin.sync_with_stdio(false);
	cin >> C;
	for (int k = 0; k < C; k++) {
		//테스트케이스마다 초기화
		for (int i = 0; i < 10; i++)
		{
			chk[i] = 0;
			for (int j = 0; j < 10; j++)
			{
				fr[i][j] = 0;
			}
		}
		cnt = ans = 0;

		//구현
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			fr[a][b] = fr[b][a] = 1;
		}

		for (int i = 1; i < n; i++)
		{
			chkfriend(0, i);
		}
		cout << ans << '\n';
	}
}