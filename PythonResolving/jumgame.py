import sys
input = sys.stdin.readline


def dp(y, x):
    if y >= N or x >= N:
        return 0
    elif y == N-1 and x == N-1:
        return 1
    elif chk[y][x] != -1:
        return chk[y][x]
    chk[y][x] = dp(y+s[y][x], x)
    chk[y][x] = max(dp(y, x+s[y][x]), chk[y][x])
    return chk[y][x]


C = int(input())
for c in range(C):
    N = int(input())
    s = []
    chk = [[-1 for i in range(N)]for j in range(N)]
    for i in range(N):
        s.append(list(map(int, (input().split()))))
    if(dp(0, 0) == 0):
        print("NO")
    else:
        print("YES")
