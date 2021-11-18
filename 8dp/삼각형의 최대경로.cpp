#include <iostream>
using namespace std;

int C, N, arr[100][100], hap[100][100];

int main()
{
    cin >> C;
    for (int ci = 0; ci < C; ci++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> arr[i][j];
            }
        }
        hap[0][0] = arr[0][0];
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)   hap[i][j] = arr[i][j] + hap[i - 1][j];
                else if (j == i) hap[i][j] = arr[i][j] + hap[i - 1][j - 1];
                else hap[i][j] = arr[i][j] + max(hap[i - 1][j], hap[i - 1][j - 1]);
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans = max(ans, hap[N - 1][i]);
        }
        cout << ans << '\n';
    }
}