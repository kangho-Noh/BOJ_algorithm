#include <iostream>
#include <stack>
using namespace std;

int dp[46];
stack<int> st;

int fib(int i){
    if(i <1 )return 0;
    if(dp[i]){ return dp[i];}
    dp[i] = fib(i-1)+fib(i-2);
    return dp[i];
}


int main(){
    dp[1] =1;
    dp[2]=1;
    fib(45);
    int T; cin>>T;
    for(int ti=0;ti<T;ti++){
        int n; cin>>n;
        int start=-1;
        while(n){
            for(int i=1;i<46;i++){
                if(dp[i]>n){
                    n-=dp[i-1];
                    st.push(dp[i-1]);
                    break;
                }
            }
        }

        while(!st.empty()){
            cout<<st.top()<<' ';
            st.pop();
        }
        cout<<'\n';
    }
}