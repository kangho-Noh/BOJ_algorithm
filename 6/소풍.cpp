#include <iostream>
using namespace std;

int C, n, m, cnt, ans;
int chk[10], fr[10][10]; //chk�� ¦�� �������� �л��� 0 �������� 1, fr�� ¦�� ģ���� fr[i][j] == 1 

void chkfriend(int a, int b)
{
	
	//ģ���� �ƴ϶�� return
	if (fr[a][b] != 1) return;
	//�̹� ¦�� ������ �л��̶�� return
	if (chk[a] == 1 || chk[b] == 1) return;
	
	//����
	chk[a] = chk[b] = 1;
	cnt++;
	//��� �л��� ¦�� �������ٸ� ans++
	if (cnt == n / 2)
	{
		ans++;
		cnt--;
		chk[a] = chk[b] = 0;
		return;
	}
	//���� ¦�� ���Ҵٸ� ����Լ�
	for (int i = a + 1; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			chkfriend(i,j);
		}
	}
	//������ �� ������ �ʱ�ȭ �� ����
	chk[a] = chk[b] = 0;
	cnt--;
	return;
}

int main() {
	cin.sync_with_stdio(false);
	cin >> C;
	for (int k = 0; k < C; k++) {
		//�׽�Ʈ���̽����� �ʱ�ȭ
		for (int i = 0; i < 10; i++)
		{
			chk[i] = 0;
			for (int j = 0; j < 10; j++)
			{
				fr[i][j] = 0;
			}
		}
		cnt = ans = 0;

		//����
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