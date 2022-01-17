#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    deque<int> v_odd, v_even;
    for (int t = 1; t <= T; t++) {
        v_odd.clear();
        v_even.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a % 2 == 0) {
                v_even.push_back(a);
            } else {
                v_odd.push_back(a);
            }
        }
        sort(v_even.begin(), v_even.end());
        sort(v_odd.begin(), v_odd.end());
        int answer = 0;
        while (!v_even.empty() && !v_odd.empty()) {

            int maxInt;
            if (v_even.back() > v_odd.back()) {
                maxInt = v_even.back();
                v_even.pop_back();
                if (!v_even.empty()) {
                    v_even.pop_front();
                    answer += maxInt;
                } else {
                    answer += v_odd.back();
                    v_odd.pop_back();
                }
            } else {
                maxInt = v_odd.back();
                v_odd.pop_back();
                if (!v_odd.empty()) {
                    v_odd.pop_front();
                    answer += maxInt;
                } else {
                    answer += v_even.back();
                    v_even.pop_back();
                }
            }
        }

        while(!v_even.empty()){
            answer+=v_even.back();
            v_even.pop_back();
            v_even.pop_front();
        }
        while(!v_odd.empty()){
            answer+=v_odd.back();
            v_odd.pop_back();
            v_odd.pop_front();
        }

        cout << '#' << t << ' ' << answer << '\n';
    }
}