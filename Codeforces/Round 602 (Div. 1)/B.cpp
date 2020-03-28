#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

bool comp1(pair<int,int> a, pair<int,int> b){
    if(a.first>b.first){
        return true;
    }
    else if(a.first==b.first){
        return a.second<b.second;
    }
    return false;
}

bool comp2(pair<int,int> a, pair<int,int> b){
    if(a.second<b.second) return true;
    return false;
}

void solve(){
    int n,q;
    cin>>n;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(arr, arr+n, comp1);
    vector<pair<int,int>> ans[n];
    for(int i=1;i<=n;i++){
        ans[i-1].resize(i);
        for(int j=0;j<i;j++){
            ans[i-1][j] = arr[j];
        }
        sort(ans[i-1].begin(), ans[i-1].end(), comp2);
    }
    cin>>q;
    while(q--){
        int k,p;
        cin>>k>>p;
        cout<<ans[k-1][p-1].first<<"\n";
    }
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}