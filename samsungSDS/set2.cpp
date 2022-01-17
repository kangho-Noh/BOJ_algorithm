#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> vv;
int chk[28];
int ans;

bool isDup(vector<int> &vector, vector<int> &vector1);

void recursive(int now, int depth) {
    vector<int> nv = vv[now];
    for (int i:nv) {
        if (chk[i]) return;
    }
    for (int i:nv) {
        chk[i] = 1;
    }
    if (ans < depth) ans = depth;

    for (int i = now +1; i < vv.size(); i++) {
        recursive(i, depth + 1);
    }

    for (int i:nv) {
        chk[i] = 0;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ans = 0;
        vector<string> v;
        memset(chk, 0, sizeof(chk));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        vv.clear();

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    string s1 = v[i];
                    string s2 = v[j];
                    string s3 = v[k];
                    bool found = true;
                    for (int ind = 0; ind < 4; ind++) {
                        if (s1[ind] == s2[ind] && s2[ind] == s3[ind]) {

                        } else if (s1[ind] != s2[ind] && s1[ind] != s3[ind] && s2[ind] != s3[ind]) {

                        } else {
                            found = false;
                            break;
                        }
                    }
                    if(found){
                        //(i,j,k) °¡´É
                        vector<int> newset;
                        newset.push_back(i);
                        newset.push_back(j);
                        newset.push_back(k);
                        vv.push_back(newset);
                    }
                }
            }
        }
        int final;
        for(final=1;final<vv.size();final++){
            if(!isDup(vv[0],vv[final])) break;
        }
        for(int i=0;i<final;i++){
            recursive(i,1);
        }
        cout << '#' << t + 1 << ' ' << ans << '\n';
    }
}

bool isDup(vector<int> &v1, vector<int> &v2) {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(v1[i] == v2[j]) return true;
        }
    }
    return false;
}
