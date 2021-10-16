#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<int> a(2*n,0);
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int m = 987654321;
    for(int i=0;i<n;i++){
        m = min(m, a[i]+a[2*n-i-1]);
    }
    cout<<m<<'\n';
}