#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    unsigned long long k;

    cin>>n>>k;
    vector<int> work(n);
    for(int i=0;i<n;i++){
        cin>>work[i];
    }
    sort(work.begin(), work.end());

    // 작업속도 = 인원수 * 제일 낮은 수
    //제일 낮은사람 팀에 n-1명 넣고 시작
    //숫자 높은사람 한명씩 반대쪽팀으로 넘기면서 한바쿠
    //가장 높은 숫자 저장해서 출력
    long long team1 = work[0]*(n-1);
    long long team2 = work[n-1];
    long long Max = team1+team2;
    for(int i=1;i<n-1;i++){
        team1 = work[0]*(n-1-i);
        team2 = work[n-1-i]*(i+1);
        Max = max(Max, team1+team2);
    }

    if(k%Max == 0){
        cout<<k/Max<<'\n';
    }else{
        cout<<k/Max+1<<'\n';
    }
}