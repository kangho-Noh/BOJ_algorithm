#include <iostream>
using namespace std;

unsigned long long Fibo[91];

int main()
{
	Fibo[1] = 1;
	for (int i = 2; i < 91; i++)
	{
		Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
	}
	int n; cin >> n;
	cout << Fibo[n] << '\n';
}