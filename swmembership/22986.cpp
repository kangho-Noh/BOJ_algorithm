#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    long long t,n,k;
    cin>>t;

    while(t--){
        cin>>n>>k;
        long long start = n-k;
        if(start<1) start = 1;
        long long hap = start+n;
        long long gap = n-start;
        long long ans;
        if(gap==0){
            ans = 4*n;
        }else if(gap%2==0){
            ans = hap*gap/2 + (start+gap/2);
            ans *=4;
        }else{
            ans = hap*(gap+1)/2;
            ans*=4;
        }
        cout<<ans<<'\n';
    }
}