//
// Created by 노강호 on 2021/09/05.
//

#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int c,d,n; cin>>c;
    while(c--){
        long long modcnt[1000001] = {0}; // modcnt[i] : 나머지가 i인 부분합의 개수
        long long sum = 0;
        cin>>d>>n;
        // 부분합의 나머지 계산 후 modcnt[나머지]++
        for(int i=0;i<n;i++){
            int a; cin>>a;
            sum = (sum+a)%d;
            modcnt[sum]++;
        }
        long long ans = modcnt[0];//나머지가 0인경우 조합을 안해도 세야함
        // Combination 계산 (나머지가 0인 부분합C2 ~나머지가 d-1인 부분합C2)
        for(int i=0;i<d;i++){
            if(modcnt[i]>1)
                ans += (modcnt[i]*(modcnt[i]-1))/2;
        }
        cout<<ans<<'\n';
    }
}