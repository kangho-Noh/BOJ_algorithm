//슬라이딩 윈도우 기법으로 풀기
#include <iostream>
#include <deque>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,l; cin>>n>>l;
    deque<pair<int,int>> dq; //(number, ind)
    for(int i=1;i<=n;i++){
        int a; cin>>a;
        if(!dq.empty()){
            if(dq.front().second<i-l+1) dq.pop_front();
        }
        while(!dq.empty()&&dq.back().first>a ) dq.pop_back();
        dq.push_back(make_pair(a, i));
        cout<<dq.front().first<<' ';
    }
    cout<<'\n';
}

// priority queue 로 풀기
//#include <iostream>
//#include <queue>
//using namespace std;
//
//priority_queue<pair<int,int>> pq; //(number, index);
//
//int main(){
//    cin.tie(0);
//    ios_base::sync_with_stdio(false);
//    int n,l; cin>>n>>l;
//    for(int i=1;i<=n;i++){
//        int a; cin>>a;
//        pq.push(make_pair(-a, i));
//        int left = i-l+1;
//        int ind = pq.top().second;
//        int num = -pq.top().first;
//        while(ind<left){
//            pq.pop();
//            num = -pq.top().first;
//            ind = pq.top().second;
//        }
//        cout<<num<<' ';
//    }
//    cout<<'\n';
//}