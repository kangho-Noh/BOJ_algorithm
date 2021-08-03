#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout<< setprecision(7);
    cout<<fixed;
    int a,d,k; cin>>a>>d>>k;
    float win_rate = d/100.0;
    float lose_rate = 1-win_rate;
    float learn_rate = k/100.0;
    float ans = win_rate * a;
    int t = a;
    while(win_rate<1){
        t+=a;
        float nxt_win_rate = win_rate+win_rate*learn_rate;
        float nxt_lost_rate = 1-nxt_win_rate;
        if(nxt_win_rate >1) nxt_win_rate=1;
        ans+=lose_rate*nxt_win_rate*t;
        lose_rate = lose_rate*nxt_lost_rate;
        win_rate = nxt_win_rate;
    }
    cout<<ans<<'\n';
}
