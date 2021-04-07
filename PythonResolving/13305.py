n = int(input())
bridge = list(map(int, input().split()))
cost = list(map(int, input().split()))

ans = 0
mincost = cost[0]
distance = 0
for i in range(n):
    if mincost > cost[i] or i == n-1:
        ans += distance*mincost
        mincost = cost[i]
        distance = 0
    if i < n-1:
        distance += bridge[i]
print(ans)
