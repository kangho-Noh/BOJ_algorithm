#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int n;cin>>n;
    vector<pair<ll,ll>> pol(n);
    for(int i=0;i<n;i++){
        cin>>pol[i].first>>pol[i].second;
    }
    ll thy,thx; cin>>thy>>thx;

    int checkmate[4] = {0,0,0,0}; //0위 1오른 2아래 3왼
    for(auto i:pol){
        ll y = i.first-thy, x = i.second-thx; //도둑을 0,0
        if(y>=0 && x>=0){ //1사분면
            if(y>=x) checkmate[0] = 1;
            if(x>=y) checkmate[1] = 1;
        }
        if(y>=0 && x<=0){ //2사분면

            if(y>=abs(x)) checkmate[0] = 1;
            if(abs(x)>=y) checkmate[3] = 1;
        }if(y<=0 && x<=0){ //3사분면

            if(abs(y)>=abs(x)) checkmate[2] = 1;
            if(abs(x)>=abs(y)) checkmate[3] = 1;
        }if(y<=0 && x>=0){ //4사분면

            if(abs(y)>=x) checkmate[2] = 1;
            if(x>=abs(y)) checkmate[1] = 1;
        }
    }
    int ans=0;
    for(auto i :checkmate) if(i)ans++;
    if(ans<4) cout<<"YES\n";
    else cout<<"NO\n";
}