#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int,int>> adj[20001];
bool chk[20001][20001];

void dfs(int a, int b, int road) {
    if(a==b || chk[a][b]) return;
    adj[a].emplace_back(make_pair(b,road));
    adj[b].emplace_back(make_pair(a,road));
    chk[a][b] = chk[b][a] = true;
    for (auto &next:adj[a]) {
        dfs(next.first, b, road+next.second);
    }
    for (auto &next:adj[b]) {
        dfs(next.first, a, road + next.second);
    }

}

void solve(int T) {
    int ans1 = 0;
    int ans2 = 2100000000;
    int n;
    cin >> n;
    for (int i = 0; i < 20001; i++)
        memset(chk[i], 0, sizeof(chk[i]));
    for (auto &i : adj) {
        i.clear();
    }
    int loop = n - 1;
    while (loop--) {
        int a, b, road;
        cin >> a >> b >> road;
        dfs(a, b, road);
    }


    for(int i=1;i<=n;i++){
        int hap = 0;
        for(auto& p:adj[i]){
            hap+=p.second;
        }
        if (hap < ans2) {
            ans2 = hap;
            ans1 = 1;
        }
        if (hap == ans2) {
            ans1++;
        }
    }

    printf("#%d %d %d\n", T, ans1, ans2);
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}