#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

// a: 배열 a
// tree: 세그먼트 트리
// node: 세그먼트 트리 노드 번호
// node가 담당하는 합의 범위가 start ~ end
ll init(vector<ll> &a, vector<ll> &tree, int node, int start, int end){
    if(start == end){
        return tree[node] = a[start];
    }
    else{
        return tree[node] = init(a,tree,node*2,start,(start+end)/2) + init(a,tree,node*2+1,(start+end)/2+1, end);
    }
}

// node가 담당하는 구간이 start~end, 구해야 하는 합의 범위는 left~right
ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
    if(left>end || right<start){
        return 0;
    }if(left<=start && end<= right){
        return tree[node];
    }
    return sum(tree,node*2, start, (start+end)/2, left,right)
        + sum(tree, node*2+1, (start+end)/2+1,end,left,right);

}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
    if(index<start||index>end)return;
    tree[node] = tree[node] + diff;
    if(start!=end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1,(start+end)/2+1,end,index,diff);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,m,k;
    cin>>n>>m>>k;
    int h = (int)ceil(log2(n));
    int tree_size = (1<<(h+1)); //2^(h+1) 비트연산하면 빨라서
    vector<ll> num(n);
    vector<ll> tree(tree_size);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    init(num, tree, 1, 0, n-1);

    for(int i=0;i<m+k;i++){
        int a; cin>>a;
        if(a==1){
            int b; ll c; cin>>b>>c;
            ll diff = c-num[b-1];
            num[b-1] = c;
            update(tree,1,0,n-1,b-1,diff);
        }else{
            int b,c; cin>>b>>c;
            cout<<sum(tree,1,0,n-1,b-1,c-1)<<'\n';
        }
    }
}