//https://www.acmicpc.net/problem/10830
#include <iostream>
using namespace std;

struct Matrix
{
	long long matrix[5][5];
	int size;
	Matrix()
	{

	}
	Matrix(int size)
	{
		this->size = size;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	Matrix operator*(Matrix& b) 
	{
		Matrix tmp(size);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)
				{
					tmp.matrix[i][j] += this->matrix[i][k] * b.matrix[k][j];
					tmp.matrix[i][j] %= 1000;
				}
			}
		}
		return tmp;
	}
};

long long N, B;
Matrix m;

Matrix squareMatrix(long long B)
{
	if (B == 1) return m;
	if (B % 2 == 1)
	{
		return squareMatrix(B - 1) * m;
	}
	else
	{
		Matrix tmp = squareMatrix(B / 2);
		return tmp * tmp;
	}
}

int main()
{
	cin >> N >> B;
	m.size = N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> m.matrix[i][j];
			m.matrix[i][j] %= 1000;
		}
	}

	Matrix ans = squareMatrix(B);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ans.matrix[i][j] << ' ';
		}
		cout << '\n';
	}
}