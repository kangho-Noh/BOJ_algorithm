#include <iostream>
using namespace std;

long long height[100001], ans;
int C;

void fence(int left, int right)
{
    //������� : ��Ÿ���� �ϳ��� ���(left == right-1)
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
    int lo = half -1, hi = half;
    long long h = min(height[lo], height[hi]);
    long long size;

    while (left <= lo && hi < right)
    {
        size = width * h;
        ans = max(ans, size);

        if (lo == 0 && hi == right - 1) break;
        
        width++;
        if (lo == 0)
        {
            hi++;
            h = min(h, height[hi]);
            continue;
        }
        if (hi == right - 1)
        {
            lo--;
            h = min(h, height[lo]);
            continue;
        }
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
    while (1)
    {
        ans = 0;
        cin >> C;
        if (C == 0) return 0;
        for (int i = 0; i < C; i++)
        {
            cin >> height[i];
        }
        fence(0, C);
        cout << ans << '\n';
    }

}