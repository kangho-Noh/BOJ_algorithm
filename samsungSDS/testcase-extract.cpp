#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin>>t;
    cout<<t<<'\n';
    for(int tt=0;tt<t;tt++){
        int n,m; cin>>n>>m;
        int a,b; cin>>a>>b;
        cout<<n<<' '<<m<<'\n';
        cout<<a<<' '<<b<<'\n';
        for(int i=0;i<m;i++){
            int aa,bb; cin>>aa>>bb;
            cout<<aa<<' '<<bb<<'\n';
        }
        cout<<'\n'<<'\n';
    }
}