#include <iostream>
using namespace std;

int main(){
    string s; cin>>s;
    const int s_size = s.size();
    if(s_size == 1){
        cout<<s<< ' '<<s<<'\n';
        return 0;
    }
    if(s_size ==2){
        if(s[0]-'0'+1 == s[1]-'0'){
            cout<<s[0]<< ' '<<s[1]<<'\n';
        }
        else{
            cout<<s<< ' '<<s<<'\n';
        }
        return 0;
    }
    //1~1
    int start = s[0]-'0';
    int end = s[s_size-1]-'0';
    if(s_size==end-start+1){
        cout<<s[0]<<' '<<s[s_size-1]<<'\n';
        return 0;
    }
    //1~2
    end = (s[s_size-2]-'0')*10 + (s[s_size-1]-'0');
    int il = 10-start; // 한 자리수 개수, 차지공간
    int du = s_size-il; // 두 자리수 차지하는 공간
    if((end-9)*2 == du){
        cout<<start<<' '<<end<<'\n';
        return 0;
    }
    //1~3
    end = (s[s_size-3]-'0')*100+(s[s_size-2]-'0')*10+(s[s_size-1]-'0');
    du = 180;
    int sam = s_size-il-du; //세 자리 수 차지 공간
    if((end-99)*3 == sam){
        cout<<start<<' '<<end<<'\n';
        return 0;
    }
    //2~2
    start = (s[0]-'0')*10 + (s[1]-'0');
    end = (s[s_size-2]-'0')*10 + (s[s_size-1]-'0');
    if(s_size == (end-start+1)*2){
        cout<<start<<' '<<end<<'\n';
        return 0;
    }
    //2~3

    end = (s[s_size-3]-'0')*100+(s[s_size-2]-'0')*10+(s[s_size-1]-'0');
    du = (100-start)*2;
    sam = s_size-du;
    if(sam==(end-99)*3){
        cout<<start<< ' '<<end<<'\n';
        return 0;
    }
    //3~3
    start = (s[0]-'0')*100 + (s[1]-'0')*10 + (s[2]-'0');
    if(s_size == 3*(end-start+1)){
        cout<<start<<' '<<end<<'\n';
        return 0;
    }
}