DIVINT = 1000000000

n = int(input())
absn = abs(n)
dp = [0, 1]
for i in range(2, absn+1):
    dp.append((dp[i-2]+dp[i-1]) % DIVINT)
absans = dp[absn]
fans = 0
if n < 0 and absn % 2 == 0:
    fans = -1
elif absans == 0:
    fans = 0
else:
    fans = 1
print(fans)
print(absans)
