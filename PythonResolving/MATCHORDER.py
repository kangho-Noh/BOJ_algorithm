C = int(input())
for c in range(C):
    N = int(input())
    R = sorted(list(map(int, input().split())), reverse=True)
    K = sorted(list(map(int, input().split())), reverse=True)
    for r in R:
        if r > K[0]:
            N -= 1
            K = K[:-1]
        else:
            K = K[1:]
    print(N)
