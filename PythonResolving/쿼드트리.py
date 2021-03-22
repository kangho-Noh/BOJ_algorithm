global arr, N


def recursive(n, y, x):
    global arr, N
    if n==1:
        print(f'{arr[y][x]}',end='')
        return
    chkdif = arr[y][x]
    re = False
    for i in range(y, y+n):
        for j in range(x, x+n):
            if arr[i][j] != chkdif:
                re=True
                break
        if re==True:
            break

    if re==True:
        print('(',end='')
        recursive(n//2,y,x)
        recursive(n//2,y,x+n//2)
        recursive(n//2,y+n//2,x)
        recursive(n//2,y+n//2,x+n//2)
        print(')',end='')
    else:
        print(f'{chkdif}',end='')




def main():
    global arr, N
    N = int(input())
    arr = []
    for i in range(N):
        arr.append(input())
    recursive(N, 0, 0)

main()