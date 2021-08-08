#include <iostream>
#include <queue>
using namespace std;

int visited[1000001];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T; cin>>T;
    for(int ti=0;ti<T;ti++){
        int k; cin>>k;
        priority_queue<pair<int,int> > maxheap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>> > minheap;
        for(int ki=0;ki<k;ki++){
            char cmd; cin>>cmd;
            int num; cin>>num;
            if(cmd=='I'){
                maxheap.push(make_pair(num,ki));
                minheap.push(make_pair(num,ki));
                visited[ki]++;
            }else{
                if(num == 1){
                    while(!maxheap.empty() &&!visited[maxheap.top().second])
                        maxheap.pop();
                    if(maxheap.empty()){
                        continue;
                    }
                    visited[maxheap.top().second]=0;
                    maxheap.pop();
                }else{
                    while(!minheap.empty() &&!visited[minheap.top().second])
                        minheap.pop();
                    if(minheap.empty()){
                        continue;
                    }
                    visited[minheap.top().second]=0;
                    minheap.pop();
                }

            }
        }while(!minheap.empty() &&!visited[minheap.top().second])
            minheap.pop();while(!maxheap.empty() &&!visited[maxheap.top().second])
                maxheap.pop();
        if(maxheap.empty()){
            cout<<"EMPTY\n";
        }else{
            cout<<maxheap.top().first<<' '<<minheap.top().first<<'\n';
        }
    }
}
