#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int A,B,C;
int AB,BC,CA;
int ans;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T; cin>>T;
    for(int ti  =0 ;ti<T;ti++){
        ans = 0;
        cin>>A>>B>>C>>AB>>BC>>CA;
        for(int i=0;i<=min(A,B);i++){ //AB개수
            int j = min(B-i,C); // BC개수
            int k = min(C-j,A-i); //CA개수
            ans = max(ans,i*AB+j*BC+k*CA);
            k = min(A-i,C); //CA개수
            j = min(C-k,B-i); //BC개수
            ans = max(ans,i*AB+j*BC+k*CA);
        }
        cout<<ans<<'\n';
    }
}