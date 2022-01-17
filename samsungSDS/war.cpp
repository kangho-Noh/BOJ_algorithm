#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int chk[1001]; // 0: ���� ��, 1: A�� ����, 2:A�� ������ ����(B�� ���� -2�� ��) -1: B�� ����, -2: ��ġ����
vector<int> adj[1001]; //adj[i] : i������ ����� ��������

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
    int fight_count = 0; //��������
    int mid_count = n-2; //�̴޼�����
    
    while(con){
        con = false;
        //A����
        queue<int> a_next_queue;
        while(!a_queue.empty()){
            int now = a_queue.front();
            a_queue.pop();
            for(int next:adj[now]){
                if(chk[next] == 0){
                    chk[next] = 2; //���߿� �ѹ��� �˻�
                    a_next_queue.push(next);
                }
            }
        }

        //B����
        queue<int> b_next_queue;
        while (!b_queue.empty()) {
            int now = b_queue.front();
            b_queue.pop();
            for (int next:adj[now]) {
                if(chk[next] == 0){
                    b_count++;
                    chk[next] = -1; //Ȯ��
                    mid_count--;
                    con=true;
                    b_next_queue.push(next);
                }else if(chk[next] == 2){
                    chk[next] = -2; // Ȯ��
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


        //A ���� Ȯ�� �� a_queue ä���
        while (!a_next_queue.empty()) {
            int i = a_next_queue.front();
            a_next_queue.pop();
            //�������� �ǳʶ�
            if(chk[i] == 2){
                chk[i] = 1; //Ȯ��
                a_count++;
                mid_count--;
                a_queue.push(i);
                con = true;
            }
        }
    }
    int ans1,ans2;
    ans1 = fight_count; //��ġ ���� ����
    ans2 = b_count-a_count + 1; //a�� �̱�� ���� �ʿ��� �߰� ���� ��
    if(ans2<0) ans2 = 0; //�߰� ������ �ʿ� ������ 0
    if(ans2>mid_count+fight_count) ans2 = -1; //�߰� ������ �ʿ��ѵ�, �����ϸ� -1

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