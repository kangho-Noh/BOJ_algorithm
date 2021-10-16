#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int arr[4001], sum[4001],sum2[4001];

//arr[left,right) cost. 0<=left<right<n
double cal(int left,int right){
    double res;
    res = sum2[right]-sum2[left];
    res-= (double)pow(sum[right]-sum[left],2)/(right-left);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int b,n;
    cin>>b>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum[i+1] = sum[i]+arr[i]; //sum[k] : arr[0,k) prefix, arr[i,j) prefix = sum[j]-sum[i]
        sum2[i+1] = sum2[i] + arr[i]*arr[i]; //sum2[k] : arr[0,k)^2 prefix
    }

    double dp[31][4001] = {{0.0,},};

    for(int i=1;i<=n;i++){ //버킷 한개로 arr[0,i)덮었을 때 그 부분의 cost = dp[1][i]
        dp[1][i] =cal(0,i);
    }

        //dp[i+1][j] = min(dp[i+1][j], dp[i][j]+cal(j,n))
    for(int i=2;i<=b;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=1e9;
            for(int k=0;k<j;k++){
                dp[i][j] = min(dp[i][j],dp[i-1][k]+cal(k,j));
            }
        }

    }
    cout.precision(4);
    cout<<fixed<<dp[b][n]<<'\n';
}
