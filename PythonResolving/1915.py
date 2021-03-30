# 가장 큰 정사각형
import sys
finput = sys.stdin.readline

n, m = map(int, finput().split())
s = []
dp = [[0 for col in range(m)] for row in range(n)]
for i in range(n):
    s.append(finput())

for i in range(n):
    for j in range(m):
        dp[i][j] = int(s[i][j])
        if(i == 0 or j == 0):
            pass
        else:
            if s[i][j] == '1':

                square = True
                if(s[i-1][j-1] == '0' or s[i-1][j] == '0' or s[i][j-1] == '0'):
                    square = False
                if(square):
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1

ans = 0
for i in range(n):
    for j in range(m):
        ans = max(ans, dp[i][j])

print(ans*ans)
