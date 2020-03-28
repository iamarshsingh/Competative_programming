#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 100000008
#define INF 1000000000000000000
using namespace std;

vector<bool> p(N,true);

void sieve(){
    for(int i=2;i*i<=N;i++){
        if(p[i]){
            for(int j=(i*i);j<=N;j+=i){
                p[j]=false;
            }
        }
    }
}

void solve(){
    int n,a;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(p[a]) ans++;
    }
    cout<<ans<<"\n";
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}