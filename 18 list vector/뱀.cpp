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
	int dy = 0, dx = 1; //오른쪽 바라봄
	int ans = 0; //정답 저장 변수 (지금까지 걸린 시간)
	yx head(1, 1); //머리
	bool gameover = false;
	while (!go.empty() && !gameover)
	{
		adv now_adv = go.front();
		go.pop_front();
		//t초간 그 방향으로 전진
		int t = now_adv.time - ans;
		for (int i = 0; i < t; i++)
		{
			ans++;
			head.y += dy;
			head.x += dx;
			
			//벽이거나 몸일 때 
			if (board[head.y][head.x] == -1) 
			{
				gameover = true;
				break;
			}
			//사과 없을 때 (꼬리 줄이기)
			else if (board[head.y][head.x] == 0)
			{
				board[head.y][head.x] = -1;
				snake.push_front(yx(head.y, head.x));
				yx tail = snake.back();
				snake.pop_back();
				board[tail.y][tail.x] = 0;
			}
			//사과 있을 때
			else
			{
				board[head.y][head.x] = -1;
				snake.push_front(yx(head.y, head.x));
			}			
		}
		//방향전환
		//상하로 움직일 때
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
		//좌우로 움직일 때
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
	//벽 또는 몸에 부딪힐 때까지 쭉 전진
	while (!gameover)
	{
		ans++;
		head.y += dy;
		head.x += dx;
		//벽이거나 몸일 때
		if (board[head.y][head.x] == -1)
		{
			gameover = true;
			break;
		}
		//사과 없을 때 (꼬리 줄이기)
		else if (board[head.y][head.x] == 0)
		{
			board[head.y][head.x] = -1;
			snake.push_front(yx(head.y, head.x));
			yx tail = snake.back();
			snake.pop_back();
			board[tail.y][tail.x] = 0;
		}
		//사과 있을 때
		else
		{
			board[head.y][head.x] = -1;
			snake.push_front(yx(head.y, head.x));
		}
	}

	cout << ans << '\n';	
}