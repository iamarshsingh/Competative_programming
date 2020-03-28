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
    int n,x,a,b;
    cin>>n>>x>>a>>b;
    cout<<min(n-1, abs(a-b)+x)<<"\n";
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}