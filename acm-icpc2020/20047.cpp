#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    int finger[2];
    string a,b; cin>>a>>b;
    cin>>finger[0]>>finger[1];
    bool ans = true;

    string a_ = a.substr(0,finger[1])+ a.substr((finger[1]+1,n-finger[1]));
    int ind = 0, chk = 0;
    for(int i=0;i<n;i++){
        if(b[i]== a_[ind]){
            ind++;
        }else{
            if(i<=finger[0]) ans = false;
            if(chk) ans=false;
            if(a[finger[1]]==b[i]){
                chk=1;
            }else{
                ans=false;
            }
        }
    }
    if(ans) {
        cout<<"YES\n";return 0;
    }

    a_ = a.substr(0,finger[0])+a.substr(finger[0]+1,finger[1]-finger[0]-1)+a.substr(finger[1]+1,a.size()-finger[1]);
    //cout<<a_<<'\n';

    ind = 0;
    int fingind = 0;
    for(int i=0;i<n;i++){
        if(b[i]==a_[ind]){
            ind++;
        }else{
            if(fingind==2){
                cout<<"NO\n";
                return 0;
            }
            if(b[i]==a[finger[fingind]])
            {
                fingind++;
                continue;
            }
            else{
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
}