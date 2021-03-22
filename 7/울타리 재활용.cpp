#include <iostream>
using namespace std;

long long height[20001], N, ans;

void fence(int left, int right)
{
    //������� : ��Ÿ���� �ϳ��� ���(left == right)
    if (left == right - 1)
    {
        if (ans < height[left]) ans = height[left];
        return;
    }

    //���ؼ�
    int half = (left + right) / 2;
    //���� Ž��
    fence(left, half);
    //������ Ž��
    fence(half, right);

    int width = 2;
    long long size;
    int lo = half - 1, hi = half;
    long long h = min(height[lo], height[hi]);

    while (left <= lo && hi < right)
    {
        size = width * h;
        ans = max(size, ans);
        width++;
        if (height[lo - 1] < height[hi + 1])
        {
            hi++;
            h = min(h, height[hi]);
        }
        else
        {
            lo--;
            h = min(h, height[lo]);
        }
    }
    return;
}

int main()
{
    int C;
    cin >> C;
    for (int k = 0; k < C; k++)
    {
        ans = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> height[i];
        }
        fence(0, N);
        cout << ans << '\n';
    }
}