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
    int n;
    cin>>n;
    int g = n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            g = __gcd(g,i);
            g = __gcd(g,(n/i));
        }
    }
    cout<<g<<'\n';
}

signed main(){
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
}