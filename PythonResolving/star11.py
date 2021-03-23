global ans


def divNcon(y, x, N):
    global ans
    if N == 1:
        ans[y][x] = '*'

    # 0번째 줄
    # y는 y로 고정, x는 x+n-1일 때 *

    # 1번째 줄 ~ n-2번째줄
    # y = y + k일 때,, x는 x+(n-1)-k 또는 x+ (n-1) +k 일 때 재귀
    for i in range(y, y+N, N//3):
        for j in range(x, x+2*N, N//3):

            # n-1번째줄
            # y = y+n-1일 때, x=x부터 x=x+2n-1까지 재귀, x+2n은 공백


def main():
    global ans
    n = int(input())
    ans = [[' 'for i in range(n*2)]for j in range(n)]
    '''for i in ans:
        for j in i:
            print(j, end='')
        print()'''
    divNcon(0, 0, n)


main()
