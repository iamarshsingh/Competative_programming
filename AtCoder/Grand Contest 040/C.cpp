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
    n=n/2;
    vector<vector<int>> dp(n, vector<int>(9,0));
    dp[0] = {1,1,1,1,1,1,1,1,1};
    //aa,ab,ac,ba,bb,bc,ca,cb,cc
    for(int i=1;i<n;i++){
        dp[0] = dp[0]+dp[1]+dp[2]+dp[3]+dp[]
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