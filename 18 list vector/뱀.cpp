//https://www.acmicpc.net/problem/3190
#include <iostream>
#include <deque>
using namespace std;

struct yx
{
	int x;
	int y;
	yx(int y, int x)
	{
		this->y = y; 
		this->x = x;
	}
};

struct adv
{
	int time;
	char d;
	adv(int t, char di)
	{
		time = t;
		d = di;
	}
};

int N, K, L, X;
char C;
int board[102][102];
deque<yx> snake;
deque<adv> go;

int main()
{
	cin >> N;
	for (int i = 0; i < N + 2; i++)
	{
		board[0][i] = board[i][0] = board[N + 1][i] = board[i][N + 1] = -1;
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int y, x;
		cin >> y >> x;
		board[y][x]++;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int y;
		char c;
		cin >> y >> c;
		go.push_back(adv(y, c));
	}

	snake.push_front(yx(1, 1));
	board[1][1]--;
	int dy = 0, dx = 1; //������ �ٶ�
	int ans = 0; //���� ���� ���� (���ݱ��� �ɸ� �ð�)
	yx head(1, 1); //�Ӹ�
	bool gameover = false;
	while (!go.empty() && !gameover)
	{
		adv now_adv = go.front();
		go.pop_front();
		//t�ʰ� �� �������� ����
		int t = now_adv.time - ans;
		for (int i = 0; i < t; i++)
		{
			ans++;
			head.y += dy;
			head.x += dx;
			
			//���̰ų� ���� �� 
			if (board[head.y][head.x] == -1) 
			{
				gameover = true;
				break;
			}
			//��� ���� �� (���� ���̱�)
			else if (board[head.y][head.x] == 0)
			{
				board[head.y][head.x] = -1;
				snake.push_front(yx(head.y, head.x));
				yx tail = snake.back();
				snake.pop_back();
				board[tail.y][tail.x] = 0;
			}
			//��� ���� ��
			else
			{
				board[head.y][head.x] = -1;
				snake.push_front(yx(head.y, head.x));
			}			
		}
		//������ȯ
		//���Ϸ� ������ ��
		if (dx == 0)
		{
			if (now_adv.d == 'L')
			{
				dx = dy;
				dy = 0;
			}
			else
			{
				dx = -dy;
				dy = 0;
			}
		}
		//�¿�� ������ ��
		else
		{
			if (now_adv.d == 'L')
			{
				dy = -dx;
				dx = 0;
			}
			else
			{
				dy = dx;
				dx = 0;
			}
		}
	}
	//�� �Ǵ� ���� �ε��� ������ �� ����
	while (!gameover)
	{
		ans++;
		head.y += dy;
		head.x += dx;
		//���̰ų� ���� ��
		if (board[head.y][head.x] == -1)
		{
			gameover = true;
			break;
		}
		//��� ���� �� (���� ���̱�)
		else if (board[head.y][head.x] == 0)
		{
			board[head.y][head.x] = -1;
			snake.push_front(yx(head.y, head.x));
			yx tail = snake.back();
			snake.pop_back();
			board[tail.y][tail.x] = 0;
		}
		//��� ���� ��
		else
		{
			board[head.y][head.x] = -1;
			snake.push_front(yx(head.y, head.x));
		}
	}

	cout << ans << '\n';	
}