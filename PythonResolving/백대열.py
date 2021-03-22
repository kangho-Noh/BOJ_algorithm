#https://www.acmicpc.net/problem/14490
a, b = map(int,input().split(':'))
ch = False
if(a<b):
    temp = a
    a = b
    b = temp
    ch = True
ta=a
tb=b
while(b!=0):
    n = a%b
    a=b
    b=n
if ch==False:
    print(round(ta/a),round(tb/a),sep=':')
else:
    print(round(tb/a),round(ta/a),sep=':')