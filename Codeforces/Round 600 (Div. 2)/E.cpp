#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

int n,m;
vector<pair<int,int>> arr;
vector<bool> cov;

void solve(){
    int a,b;
    cin>>n>>m;
    arr.resize(n);
    cov.resize(m+1);
    vector<int> dp(m+1,m);
    for(int i=0;i<n;i++){
        cin>>a>>b;
        arr[i].first = a-b;
        arr[i].second = a+b;
        for(int j=arr[i].first-arr[i].second; j<=arr[i].first+arr[i].second; j++){
            cov[j]=true;
        }
    }
    dp[m] = 0;
    for(int i=m;i>=1;i--){
        
    }

    cout<<cal(1LL)<<"\n";
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}