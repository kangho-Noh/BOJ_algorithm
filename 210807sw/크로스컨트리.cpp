#include <iostream>
using namespace std;



int main(){
    int T; cin>>T;
    for(int ti = 0; ti<T;ti++){
        int cnt[201]= {0}; //도착한 인원 수
        int arrive[1001]={0};
        int all_score[201]={0};
        int fifth[201]={0};
        int fifth_score[201]={0};
        int n; cin>>n;
        for(int i=0;i<n;i++){
            int arrived_team; cin>>arrived_team;
            cnt[arrived_team]++;
            arrive[i] = arrived_team;
        }
        int score = 0;
        for(int i=0;i<n;i++){
            int nowteam = arrive[i];
            if(cnt[nowteam]<6){
                continue;
            }
            else{
                score++;
                fifth[nowteam]++;
                if(fifth[nowteam]<5)
                    all_score[nowteam]+=score;
                if(fifth[nowteam]==5){
                    fifth_score[nowteam] = score;
                }
            }
        }
        int MAX = 987654321;
        int ans = -1;
        for(int i=1;i<201;i++){
            if(!all_score[i]) continue;
            if(all_score[i]<MAX)
            {
                MAX = all_score[i];
                ans = i;
            }else if(all_score[i]==MAX){
                if(fifth_score[i]<fifth_score[ans])
                    ans = i;
            }
        }
        cout<<ans<<'\n';
    }

}