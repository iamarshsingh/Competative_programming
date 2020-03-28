#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

void solve(){
    int x,y;
    cin>>x>>y;
    if(x==1){
        if(y==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    else if(x==2 || x==3){
        if(y<=3)
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
        }
    }
    else{
        cout<<"YES\n";
    }
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}