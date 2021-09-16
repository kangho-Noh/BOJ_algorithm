//
// Created by �밭ȣ on 2021/09/16.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    bool leaf;
    char c;
    vector<Node*> next_list;
    Node(){
        leaf = false;
        c='\0';
    }
};


bool solve(string s, Node* now, int ind){
    bool ret = false;

    if(now->leaf==true){
        return true;
    }

    if(ind == int(s.size())){
        //s[ind] == leaf node
        now->leaf = true;
        if(now->next_list.empty())
            return false;
        else
            return true;
    }
    char now_char = s[ind];

    Node* target = nullptr;
    vector<Node*>& next_nodes = now->next_list;
    for(Node* next : next_nodes){
        if(next->c == now_char){
            target = next;
        }
    }

    if(target == nullptr){
        target = new Node;
        target->c = now_char;
        next_nodes.push_back(target);
    }
    ret = solve(s, target, ind+1);

    return ret;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        string answer = "YES\n";
        int n; cin>>n;
        Node* root = new Node;
        for(int i=0;i<n;i++){
            string num; cin>>num;
            if(solve(num, root,0)) answer = "NO\n";
        }

        cout<<answer;
    }

}