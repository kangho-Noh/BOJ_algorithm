#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int chk[1001]; // 0: 점령 전, 1: A가 점령, 2:A가 점령할 예정(B가 오면 -2가 됨) -1: B가 점렴, -2: 대치거점
vector<int> adj[1001]; //adj[i] : i거점과 연결된 간선모음

void solve(int t){
    memset(chk, 0, sizeof(chk));
    for(int i=0;i<1001;i++){
        adj[i].clear();
    }
    int n,m;
    cin >> n >>m;
    int A, B; cin>>A>>B;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool con = true;
    queue<int> a_queue, b_queue;
    a_queue.push(A);
    b_queue.push(B);
    chk[A] = 1;
    chk[B] = -1;
    
    int a_count = 1;
    int b_count = 1;
    int fight_count = 0; //분쟁지역
    int mid_count = n-2; //미달성지역
    
    while(con){
        con = false;
        //A전진
        queue<int> a_next_queue;
        while(!a_queue.empty()){
            int now = a_queue.front();
            a_queue.pop();
            for(int next:adj[now]){
                if(chk[next] == 0){
                    chk[next] = 2; //나중에 한번더 검사
                    a_next_queue.push(next);
                }
            }
        }

        //B전진
        queue<int> b_next_queue;
        while (!b_queue.empty()) {
            int now = b_queue.front();
            b_queue.pop();
            for (int next:adj[now]) {
                if(chk[next] == 0){
                    b_count++;
                    chk[next] = -1; //확정
                    mid_count--;
                    con=true;
                    b_next_queue.push(next);
                }else if(chk[next] == 2){
                    chk[next] = -2; // 확정
                    fight_count++;
                    mid_count--;
                }
            }
        }
        while(!b_next_queue.empty()){
            int i = b_next_queue.front();
            b_next_queue.pop();
            b_queue.push(i);
        }


        //A 거점 확정 및 a_queue 채우기
        while (!a_next_queue.empty()) {
            int i = a_next_queue.front();
            a_next_queue.pop();
            //분쟁지역 건너뜀
            if(chk[i] == 2){
                chk[i] = 1; //확정
                a_count++;
                mid_count--;
                a_queue.push(i);
                con = true;
            }
        }
    }
    int ans1,ans2;
    ans1 = fight_count; //대치 거점 개수
    ans2 = b_count-a_count + 1; //a가 이기기 위해 필요한 추가 거점 수
    if(ans2<0) ans2 = 0; //추가 거점이 필요 없으면 0
    if(ans2>mid_count+fight_count) ans2 = -1; //추가 거점이 필요한데, 부족하면 -1

    cout<<'#'<<t<<' '<<ans1<<' '<<ans2<<'\n';
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve(t+1);
    }
}