n, m = map(int, input().split())
books = list(map(int, input().split()))
books = sorted(books)
minusarr = []
plusarr = []
for b in books:
    if b < 0:
        minusarr.append(abs(b))
    else:
        plusarr.append(b)
minusarr.sort()
minus = len(minusarr)
plus = len(plusarr)
#max(plusarr) > max(minusarr)
if plus == 0:
    plusarr = minusarr
    minusarr = []
    plus = len(plusarr)
    minus = len(minusarr)
if minus > 0 and plus > 0 and max(minusarr) > max(plusarr):
    temp = minusarr
    minusarr = plusarr
    plusarr = temp
    minus = len(minusarr)
    plus = len(plusarr)

ans = max(plusarr)
if plus <= m:
    plus = 0
    plusarr = []
    n -= plus
else:
    plusarr = plusarr[:-m]
    n -= m
divplus = plus % m
divminus = minus % m
if divplus:
    plus -= divplus
    n -= divplus
    ans += 2*plusarr[divplus-1]
    if(plus):
        plusarr = plusarr[divplus:]
    else:
        plusarr = []
if divminus:
    minus -= divminus
    n -= divminus
    ans += 2*minusarr[divminus-1]
    if minus:
        minusarr = minusarr[divminus:]
    else:
        minusarr = []
if len(plusarr) > 0:
    for i in range(m-1, len(plusarr), m):
        ans += 2*plusarr[i]
if len(minusarr) > 0:
    for i in range(m-1, len(minusarr), m):
        ans += 2*minusarr[i]
print(ans)
