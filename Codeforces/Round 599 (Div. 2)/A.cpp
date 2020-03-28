#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    int ans=0;
    for(int i=0;i<n;i++){
        if((n-i)>=arr[i]){
            ans = max(ans, arr[i]);
        }
        if(arr[i]>=(n-i)){
            ans = max(ans, n-i);
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    randright
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}