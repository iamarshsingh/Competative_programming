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
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr, arr+n);
    int pre[n], ans[n];
    pre[0] = arr[0];
    ans[0] = arr[0];
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1]+arr[i];
        if(i<m){
            ans[i] = pre[i];
        }
        else{
            ans[i] = pre[i] + ans[i-m];
        }
    }
    
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<"\n";
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}