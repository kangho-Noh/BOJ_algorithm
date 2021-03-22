X, Y = input().split()

if len(X)>len(Y):
    temp = X
    X = Y
    Y = temp

ans=51
for i in range(len(Y)-len(X)+1):
    cnt=0
    for j in range(len(X)):
        if Y[i+j] != X[j]:
            cnt+=1
    ans = min(ans,cnt)
print(ans)