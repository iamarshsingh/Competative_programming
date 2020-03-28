#include <bits/stdc++.h>
#define int unsigned long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

void solve(){
    int l,r,ans;
    cin>>l>>r;
    int lxr = (l^r);
    for(ans=0;ans<lxr;ans=((ans*2)+1));
    ans=(ans|r);
    cout<<ans<<"\n";
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