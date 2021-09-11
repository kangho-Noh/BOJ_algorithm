#include <string>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int number = 1000001; // 구하고자 하는 소수의 범위
int primeNum[1000001];

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < sqrt(n); i++)
        if (n % i == 0)
            return false;

        return true;
}


string n_jinsu(int n, int k){
    int nn = n;
    string ret;
    while(nn!=0){
        int mod = nn%k;
        nn=nn/k;

        ret+=char(48+mod);
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

int solution(int n, int k) {
    int answer = 0;
    string njinsu = n_jinsu(n,k);
    string nowint;
    for(int i=0;i<njinsu.size();i++){
        if(njinsu[i]!='0')
            nowint+=njinsu[i];
        if(njinsu[i]=='0' || i==njinsu.size()-1) {

            if(nowint!=""){
                long long now = stoll(nowint);
                if(isPrime(now))
                    answer++;
            }
            nowint="";
            continue;
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> v;
    vector<int> vv(10,0);
    v.push_back(vv);
    v.push_back(vv);
    cout<<v.size()<<' '<<v[0].size();
}