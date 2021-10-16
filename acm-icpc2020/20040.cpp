// 분리 집합.
#include <iostream>
using namespace std;

int parent[500001];

int find_parent(int n){
    if(parent[n]==n) return n;
    return parent[n] = find_parent(parent[n]);
}

void union_parent(int n,int m){
    int pn = find_parent(n);
    int pm = find_parent(m);
    if(pn>pm) parent[pm] = pn;
    else parent[pn] = pm;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    int ans = 0;
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;
        if(find_parent(a) == find_parent(b))
        {
            ans = i;
            break;
        }else{
            union_parent(a,b);
        }
    }
    cout<<ans<<'\n';
}