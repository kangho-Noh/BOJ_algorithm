#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    char str[1001];
    cin>>str;
    vector<string> v;
    for(int i=0;i<strlen(str);i++){
        v.emplace_back(str+i);
    }
    sort(v.begin(), v.end());
    for(string i : v) cout<<i<<'\n';
}