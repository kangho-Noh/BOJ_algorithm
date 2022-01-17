#include <iostream>
#include <vector>

using namespace std;

int arr[100000];
int n, last, alltime;

int cango(int start, int &i, vector<int> rest) {
    //안쉬고 갈 수 있을 때
    if (start + 6 >= i) {
        return i - start + 1;
    }
    //한 번 쉬고 갈 수 있을 때
    int lastrest = start;
    for (int i:rest) {
        if (start + 6 < i) break;
        lastrest = i;
    }
    if (lastrest == start) return 0; // 더이상 못감
    int tt = lastrest - start + 2; //다시 출발하기까지 걸린 시간
    if (lastrest + 6 >= i) {
        return tt + i - lastrest + 1;
    }
    //한 번 더 쉬고 갈 수 있을 때
    int lastlastrest = lastrest;
    for (int i:rest) {
        if (lastrest + 6 < i) break;
        lastlastrest = i;
    }
    if (lastrest == lastlastrest) return 0; //더이상 못감
    tt += lastlastrest - lastrest + 2;
    if (lastlastrest + (15 - tt) >= i) {
        return tt + i - lastlastrest + 1;
    }
}

int recursive(int start) {

    if (start == last) {
        return alltime;
    }
    int end = start + 15;
    if (end > n - 1) end = n - 1;
    vector<int> camp, rest;
    for (int i = start; i <= n - 1; i++) {
        if (arr[i] == 3) camp.emplace_back(i);
        if (arr[i] == 2) rest.emplace_back(i);
    }
    int lastcamp = -1;
    for (auto &i:camp) {
        if (cango(start, i, rest)) {
            lastcamp = i;
        }
    }
    if (lastcamp == -1)
        return -1;
    return recursive(lastcamp);
}

void solve(int t) {
    cin >> n;
    last = alltime = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 3) last = i;
    }

    alltime = recursive(0);

    printf("#%d %d\n", t, alltime);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
    return 0;
}