#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a[6], b[6];

    for(int i=0;i<6;i++){
        cin>>a[i];
    }

    for(int i=0;i<6;i++){
        cin>>b[i];
    }

    int wins=0;
    int alls = 0;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(a[i]>b[j]) wins++;
            alls++;
        }
    }
    int gcdd = gcd(wins, alls);
    cout<<wins/gcdd<<'/'<<alls/gcdd<<'\n';

}