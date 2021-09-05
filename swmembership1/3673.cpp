//
// Created by �밭ȣ on 2021/09/05.
//

#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int c,d,n; cin>>c;
    while(c--){
        long long modcnt[1000001] = {0}; // modcnt[i] : �������� i�� �κ����� ����
        long long sum = 0;
        cin>>d>>n;
        // �κ����� ������ ��� �� modcnt[������]++
        for(int i=0;i<n;i++){
            int a; cin>>a;
            sum = (sum+a)%d;
            modcnt[sum]++;
        }
        long long ans = modcnt[0];//�������� 0�ΰ�� ������ ���ص� ������
        // Combination ��� (�������� 0�� �κ���C2 ~�������� d-1�� �κ���C2)
        for(int i=0;i<d;i++){
            if(modcnt[i]>1)
                ans += (modcnt[i]*(modcnt[i]-1))/2;
        }
        cout<<ans<<'\n';
    }
}