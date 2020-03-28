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
    int n,ans=0;
    cin>>n;
    int a[n], b[n];
    vector<int> diff(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>b[i];
        diff[i] = a[i]-b[i];
        if(diff[i]>0){
            ans=2;
        }
        if(a[i]!=b[i]){
            if(ans==0){
                ans++;
            }
            else if(diff[i] != diff[i-1]){
                ans++;
            }
        }
    }
    if(ans<2){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}