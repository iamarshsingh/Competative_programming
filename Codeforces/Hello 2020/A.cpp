#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

void solve(){
    int n,m,x;
    cin>>n>>m;
    string a[n];
    string b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int q;cin>>q;
    while(q--){
        cin>>x;
        x--;
        cout<<(a[x%n]+b[x%m])<<"\n";
    }
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}