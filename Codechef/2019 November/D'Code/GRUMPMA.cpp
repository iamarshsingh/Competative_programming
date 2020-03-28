#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int n,k,m,a;
    cin>>n>>k>>m;
    vector<int> ans(k+1LL,0LL);
    ans[0] = 1LL;
    for(int i=0;i<n;i++){
        cin>>a;
        int j = a%m;
        if(j==0){
            j+=m;
        }
        while(j<=k){
            ans[j] = (ans[j] + ans[j-1])%MOD;
            j+=m;
        }
        // for(int i=0;i<=k;i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<"\n";
    }
    // for(int i=0;i<=k;i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<"\n";
    cout<<(ans[k]%MOD)<<"\n";
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