#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,K,ans;
vector<int> v;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    for(int ti=0;ti<t;ti++){
        cin>>n>>K;
        ans = 0;
        v.clear();
        for(int i=0;i<n;i++){
            int a; cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        int st = 0;
        int en = v.size()-1;
        int MIN = 987654321;
        while(st<en){
            int hap = v[st]+v[en];
            int cha = hap-K;
            if(abs(cha)<MIN){
                MIN = abs(cha);
                ans = 1;
            }else if(abs(cha) == MIN){
                ans++;
            }
            if(cha<0){
                st++;
            }else{
                en--;
            }
        }
        cout<<ans<<'\n';
    }
}