import copy
global n, ans

def left(temp, depth):
    global n, ans
    if depth==5:
        maxint=0
        for i in range(n):
            for j in range(n):
                maxint = max(maxint,temp[i][j])
        ans = max(maxint, ans)
        return
        
    chk = [[0 for i in range(n)]for j in range(n)]
    for i in range(n):
        for j in range(n):
            if temp[i][j] == 0:
                for k in range(j+1,n):
                    if temp[i][k] !=0:
                        t = temp[i][j]
                        temp[i][j] = temp[i][k]
                        temp[i][k] = t
   
    for j in range(n):
        for i in range(n-1):
            if chk[j][i]==0 and temp[j][i] == temp[j][i+1]:
                chk[j][i] = chk[j][i+1] = 1
                temp[j][i] *=2
                temp[j][i+1] = 0

    for j in range(n):
        for i in range(n):
            if temp[j][i] == 0:
                for k in range(i+1,n):
                    if temp[j][k] !=0:
                        t = temp[j][i]
                        temp[j][i] = temp[j][k]
                        temp[j][k] = t
    tmp = copy.deepcopy(temp)
    left(tmp, depth+1)
    tmp = copy.deepcopy(temp)
    tmp = rotate(tmp)
    left(tmp, depth+1)
    tmp = copy.deepcopy(temp)
    tmp = rotate(tmp)
    tmp = rotate(tmp)
    left(tmp, depth+1)
    tmp = copy.deepcopy(temp)
    tmp = rotate(tmp)
    tmp = rotate(tmp)
    tmp = rotate(tmp)
    left(tmp, depth+1)

def rotate(temp):
    global n
    res = []
    for i in range(n):
        rev = []
        for j in range(n):
            rev.append(temp[j][i])
        rev.reverse()
        res.append(rev)
    return res

def main():
    global n, ans
    n = int(input())
    arr = [[0 for i in range(n)]for j in range(n)]
    for i in range(n):
        s= input().split()
        for j in range(n):
            arr[i][j] = int(s[j])
    
    ans = 0

    tmp = copy.deepcopy(arr)
    left(tmp, 0)
    tmp = copy.deepcopy(arr)
    tmp = rotate(tmp)
    arr = rotate(arr)
    left(tmp, 0)
    tmp = copy.deepcopy(arr)
    tmp = rotate(tmp)
    arr = rotate(arr)
    left(tmp, 0)
    tmp = copy.deepcopy(arr)
    tmp = rotate(tmp)
    arr = rotate(arr)
    left(tmp, 0)
    print(ans)

main()