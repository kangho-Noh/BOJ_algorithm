N, K, L = map(int,input().split())
rnd = 1 #라운드 수
pcnt=N; #현재 살아남은 플레이어 수
while(1):
  if abs(K-L)==1 and min(K,L)%2==1:
    break
  if pcnt%2==1:
    pcnt= pcnt//2+1
  else:
    pcnt=pcnt//2
  rnd+=1
  if K%2==1:
    K = K//2+1
  else:
    K=K//2
  if L%2==1:
    L = L//2+1
  else:
    L=L//2
print(rnd)