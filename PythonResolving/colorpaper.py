global n, s, cnt


def divNcon(y, x, size):
    global n, s, cnt
    if size == 1:
        cnt[s[y][x]] += 1
        return
    div = False
    for i in range(y, y+size):
        for j in range(x, x+size):
            if s[i][j] != s[y][x]:
                div = True
    if div:
        divNcon(y, x, size//2)
        divNcon(y+size//2, x, size//2)
        divNcon(y, x+size//2, size//2)
        divNcon(y+size//2, x+size//2, size//2)
    else:
        cnt[s[y][x]] += 1
    return


def main():
    global n, s, cnt
    n = int(input())
    s = []
    for i in range(n):
        s.append(list(map(int, (input().split(' ')))))
    cnt = [0, 0]
    divNcon(0, 0, n)
    print(cnt[0], cnt[1], sep='\n')


main()
