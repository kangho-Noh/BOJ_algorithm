#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T; cin>>T;
    for(int ti=0;ti<T;ti++){
        int C,D,d; cin>>C>>D>>d;
        vector<int> x;
        vector<int> y;
        while(1){
            int a; cin>>a;
            if(!a) break;
            x.push_back(a);
        }while(1){
            int a; cin>>a;
            if(!a) break;
            y.push_back(a);
        }
        int xsize = x.size();
        int ysize = y.size();
        if(ysize>xsize){
            vector<int> temp = x;
            x=y;
            y=temp;
        }
        xsize = x.size();
        ysize = y.size();
        int rest = xsize-ysize;
    }
}