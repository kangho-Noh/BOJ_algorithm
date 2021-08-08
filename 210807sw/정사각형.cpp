#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<pair<int,int>> v;
float len[3001][3001];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T; cin>>T;
    for(int ti=0;ti<T;ti++){
        float ans = 0;
        int n; cin>>n;
        for(int i=0;i<n;i++){
            int x,y; cin>>x>>y;
            v.push_back(make_pair(x,y));
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                float l = sqrt(pow(v[i].first-v[j].first,2)+pow(v[i].second-v[j].second,2));
                len[i][j] = len[j][i] = l;
            }
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                float nowlen = len[i][j];
                if(nowlen<=ans) continue;
                vector<int> v1, v2;
                for(int k=0;k<n;k++){
                    if(k==i||k==j)continue;
                    if(len[k][i] == nowlen) v1.push_back(k);
                    if(len[k][j] == nowlen) v2.push_back(k);
                }
                for(int k : v1){
                    for(int t:v2){
                        if(len[k][t] == nowlen)
                            ans = nowlen;
                    }
                }
            }
        }
        cout<<ans*ans<<'\n';
    }
}