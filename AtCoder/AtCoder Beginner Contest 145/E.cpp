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
    int n,t;
    cin>>n>>t;
    int tim[n], hap[n];
    for(int i=0;i<n;i++){
        cin>>tim[i]>>hap[i];
    }
    int ans=0;
    vector<vector<int>> dp(n+1, vector<int>(t+10000LL, 0LL));
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<t+hap[i-1];j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=t+tim[i-1];j++){
            if(j>0){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            if(j>=tim[i-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-tim[i-1]] + hap[i-1]);
            }
            ans = max(dp[i][j], ans);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<t+tim[i-1];j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<ans<<"\n";
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}