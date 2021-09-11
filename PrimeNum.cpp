#include <iostream>
#include <cmath>
using namespace std;

int number = 1000001; // ���ϰ��� �ϴ� �Ҽ��� ����
int primeNum[1000000];

void primeNumberSieve()
{
    // primeNum �迭 �ʱ�ȭ
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        // primeNum[i] �� 0�̸� �̹� �Ҽ��� �ƴϹǷ� continue
        if (primeNum[i] == 0)
            continue;
        // i*k (k<i) ������ ���� �̹� �˻������Ƿ� j�� i*i ���� �˻����ش�.
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }

    // �Ҽ� ���
    for (int i = 2; i <= number; i++)
    {
        if (primeNum[i] != 0)
            printf("%d\n", primeNum[i]);
    }
}
int main()
{
    primeNumberSieve();
}