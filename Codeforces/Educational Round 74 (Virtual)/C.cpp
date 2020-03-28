#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int h,n;
    cin>>h>>n;
    int arr[n+1];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n, greater<int>());
    arr[n] = 0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(arr[i]>(arr[i+1]+1)){
            ans++;
        }
        else i++;
    }
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