#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
int mapp[1001][1001];
int m,n;
int chk[1001][1001]; //방문 여부
priority_queue<pair<int,pair<int,int>>> pq;

//1 0, 0 1, -1 0, 0 -1
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int djikstra(){
    //ans 현재 공간까지의 최소비용
    // pq(
    vector<vector<int>> ans(1001,vector<int>(1001,INF));
    pq.push(make_pair(-mapp[0][0],make_pair(0,0)));
    ans[0][0] = mapp[0][0];
    while(!pq.empty()){
        int y = pq.top().second.first;
        int x = pq.top().second.second;

        int cost = -pq.top().first;
        pq.pop();
        if(cost>ans[y][x]) continue;
        for(int i=0;i<4;i++){
            int ny = dy[i]+y;
            int nx = dx[i]+x;
            if(ny<0||nx<0||ny>=m||nx>=n) continue;
            int hap = cost+mapp[ny][nx];
            if(mapp[ny][nx]==-1) continue;
            if(chk[ny][nx]==1) continue;

            if(ans[ny][nx]>hap){
                ans[ny][nx] = hap;
                pq.push(make_pair(-hap,make_pair(ny,nx)));
            }
        }
        chk[y][x] =1;
    }

    return ans[m-1][n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mapp[i][j];
        }
    }
    if(mapp[0][0] == -1 || mapp[m-1][n-1] == -1){
        cout<<-1<<'\n';
        return 0;
    }
    //중간에 길막혀도 -1
    int ans = djikstra();
    if(ans==INF) cout<<-1<<'\n';
    else cout<<ans<<'\n';
}