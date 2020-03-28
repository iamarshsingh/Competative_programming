#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1e17
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int maxx = max(n,m);
    if(maxx==1){
        cout<<2<<"\n";
        return;
    }
    int arr[maxx];
    arr[0] = 1; arr[1] = 2;
    for(int i=2;i<maxx;i++){
        arr[i] = (arr[i-1] + arr[i-2])%MOD;
    }
    cout<<(((2LL*arr[maxx-1])-2) + (2LL*arr[min(n,m)-1]) + MOD)%MOD<<"\n";
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