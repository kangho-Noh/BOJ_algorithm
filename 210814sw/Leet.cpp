#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int k, ans;
string trans[26];
string origin, leet;

void dfs(int orgInd, int leetInd,int pl){
    if(orgInd==origin.size() ){
        if(leetInd == leet.size())
            ans = 1;
        return;
    }
    char now = origin[orgInd];
    int transInd = now-'a';

    //있을 때
    if(trans[transInd]!=""){
        int transSize = trans[transInd].size();
        if(leet.substr(leetInd,transSize) != trans[transInd]){
            return;
        }else{
            dfs(orgInd+1, leetInd+transSize,transSize);
        }
    }
    //없을 때
    else{

        for(int i=1;i<=k && i+leetInd<=leet.size();i++){
            trans[transInd] = leet.substr(leetInd,i);
            dfs(orgInd+1,leetInd+i,i);
            trans[transInd] = "";
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T;cin>>T;
    for(int TT=0;TT<T;TT++){
        cin>>k;
        ans = 0;
        for(int i=0;i<26;i++)trans[i] = "";
        cin>>origin>>leet;
        dfs(0,0,0);

        cout<<ans<<'\n';
    }
}