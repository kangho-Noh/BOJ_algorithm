#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct s{
    int a,b,c,d;
    int ssum,gop;
    s(int aa,int bb,int cc,int dd){
        a=aa;
        b=bb;
        c=cc;
        d=dd;
        ssum = b+c+d;
        gop = b*c*d;
    }
    bool operator<(const s& o) const{
        if(this->gop<o.gop) return true;
        else if(this->gop == o.gop){
            if(this->ssum<o.ssum) return true;
            else if(this->ssum == o.ssum){

                if(this->a < o.a) return true;
                else return false;
            }
            else return false;
        }
        else return false;
    }
};
int main(){
    int n; cin>>n;
    vector<s> ss;

    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        ss.push_back(s(a,b,c,d));

    }
    sort(ss.begin(),ss.end());
    cout << ss[0].a<<' '<<ss[1].a<<' '<<ss[2].a<<'\n';
}