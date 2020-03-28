#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define N 3000000
#define MOD 1000000007
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

int fact[N];


void preComp(int m = MOD){
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1] * i)%m;
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    preComp(m);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans += ((fact[n-i+1]*fact[i]+m)%m*(n-i+1)+m);
        ans %= m;
    }
    cout<<ans<<"\n";
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}