#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 998244353
#define N 2010
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

int dp[N][2*N];

void solve(){
    int n,k;
    cin>>n>>k;
    k%=MOD;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n==1 || k==1){
        cout<<"0\n";
        return;
    }
    if(arr[0]==arr[1]){
        dp[0][N] = k;
    }
    else{
        dp[0][N] = k-2;
        dp[0][N+1] = 1;
    }
    for(int i=1;i<n;i++){

        if(arr[i]==arr[(i+1)%n]){
            for(int j=0;j<(2*N);j++){
                dp[i][j] = (dp[i-1][j]*k) % MOD;
            }
        }
        else{
            dp[i][0] = (dp[i-1][0]*(k-2));
            dp[i][0] += dp[i-1][1];
            dp[i][0] %= MOD;

            for(int j=0;j<(2*N)-1;j++){
                dp[i][j] = ( (dp[i-1][j-1] + dp[i-1][j+1]) + (dp[i-1][j]*(k-2)) )%MOD;
            }
            dp[i][2*N-1] = dp[i-1][2*N-2];
            dp[i][2*N-1] += (dp[i-1][2*N-1]*(k-2));
            dp[i][2*N-1] %= MOD;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=N-n;j<=N+n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int ans=0;
    for(int i=N+1;i<2*N;i++) ans += dp[n-1][i];
    cout<<ans%MOD<<"\n";
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}