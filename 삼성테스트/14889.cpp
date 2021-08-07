#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[20][20];
vector<int> nowteam;
int chk[20];
int ans=987654321;

void backtracking(int now, int cnt, int sum_){
    chk[now]=1;
    for(int i:nowteam){
        sum_+=arr[i][now] + arr[now][i];
    }
    nowteam.push_back(now);
    if(cnt==n/2){
        vector<int> other;
        for(int i=0;i<n;i++){
            if(!chk[i])other.push_back(i);
        }

        int other_sum = 0;
        for(int i:other){
            for(int j:other){
                other_sum+=arr[i][j];
            }
        }
        ans = min(ans, abs(sum_-other_sum));
    }else{
        for(int i=now+1;i<n;i++){
            backtracking(i,cnt+1,sum_);
        }
    }
    chk[now]=0;
    nowteam.pop_back();
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    backtracking(0,1,0);
    cout<<ans<<'\n';
}