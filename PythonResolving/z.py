global r, c, ans


def divNcon(y, x, n):
    global r, c, ans
    if y == r and x == c:
        return
    half = n//2
    powhalf = pow(half, 2)
    if r < y+half and c < x+half:
        ans += 0
    elif r < y+half and c >= x+half:
        x += half
        ans += powhalf
    elif r >= y+half and c < x+half:
        y += half
        ans += powhalf*2
    else:
        x += half
        y += half
        ans += powhalf*3
    divNcon(y, x, half)


ans = 0
N, r, c = map(int, (input().split()))
N = pow(2, N)
divNcon(0, 0, N)
print(ans)
