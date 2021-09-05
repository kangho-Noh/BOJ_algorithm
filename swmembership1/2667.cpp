//
// Created by �밭ȣ on 2021/09/05.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,cnt;
int arr[26][26], chk[26][26];
vector<int> ans;
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

void dfs(int nowy,int nowx){
    if(nowy<0 || nowy>=n || nowx<0 || nowx>=n){
        return;
    }
    if(!arr[nowy][nowx] || chk[nowy][nowx]) return;
    cnt++;
    chk[nowy][nowx]++;
    for(int i=0;i<4;i++){
        dfs(dy[i] + nowy, dx[i] + nowx);
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        for(int j=0;j<n;j++){
            arr[i][j] = s[j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]&&!chk[i][j]){
                cnt=0;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<'\n';
    for(int i : ans) cout<< i<<'\n';
}
