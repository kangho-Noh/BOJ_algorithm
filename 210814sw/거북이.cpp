#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1}; //위 오 아 왼


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T; cin>>T;
    for(int ti  =0 ;ti<T;ti++){
        int y = 0, x=0;
        int dir = 0;
        int yy = dy[dir], xx =dx[dir];
        int miny=0, maxy = 0, minx =0,maxx = 0;
        string a; cin>>a;
        for(char now :a){
            if(now=='F'){
                y+=yy; x+=xx;
                miny = min(miny,y);
                maxy = max(maxy,y);
                minx = min(minx,x);
                maxx = max(maxx,x);
            }else if(now =='B'){
                y-=yy; x-=xx;
                miny = min(miny,y);
                maxy = max(maxy,y);
                minx = min(minx,x);
                maxx = max(maxx,x);
            }
            else if(now =='L'){
                dir--;
                if(dir<0) dir = 3;
                yy = dy[dir], xx =dx[dir];
            }else{
                dir++;
                dir%=4;
                yy = dy[dir], xx =dx[dir];
            }
        }
        cout<<(maxy-miny)*(maxx-minx)<<'\n';
    }
}