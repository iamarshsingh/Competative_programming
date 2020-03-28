#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int n,k,a;
    cin>>n>>k;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a;
        sum += a;
    }
    if(sum<=k) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
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