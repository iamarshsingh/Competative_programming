#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int n;
    cin>>n;
    int c,a,l=0,r=0;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c%2==0){
            for(int j=0;j<(c/2);j++){
                cin>>a;
                l+=a;
            }
            for(int j=(c/2);j<c;j++){
                cin>>a;
                r+=a;
            }
        }
        else{
            for(int j=0;j<(c/2);j++){
                cin>>a;
                l+=a;
            }
            cin>>a;
            pq.push(a);
            for(int j=(c/2 + 1);j<c;j++){
                cin>>a;
                r+=a;
            }
        }
        //cout<<l<<" "<<r<<"\n";
    }
    bool poss=true;
    while(!pq.empty()){
        a = pq.top();
        pq.pop();
        if(poss){
            l+=a;
        }
        else{
            r+=a;
        }
        poss=!poss;
    }
    cout<<l<<"\n";
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}