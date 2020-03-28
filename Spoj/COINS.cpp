#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

map<int,int> dp;

int cal(int n){
    if(dp.find(n)!=dp.end()){
        return dp[n];
    }
    if((n/2)+(n/3)+(n/4) <= n){
        dp[n] = n;
        return n;
    }
    dp[n] =  cal(n/2) + cal(n/3) + cal(n/4);
    return dp[n];
}

void solve(){
    int n;
    while(cin>>n){
        int ans = cal(n);
        cout<<ans<<"\n";
    }    
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}