//
// Created by �밭ȣ on 2021/09/16.
//
#include <iostream>
#include <vector>
using namespace std;

int need[1001];
vector<int> prebuild[1001];

int main(){
    int T; cin>>T;
    while(T--){
        int n,k; cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>need[i];
        }
        for(int i=0;i<k;i++){
            int a,b; cin>>a>>b;
            prebuild[b].push_back(a);
        }
        int w; cin>>w;
        long long ans;

        cout<<ans<<'\n';
    }
}

