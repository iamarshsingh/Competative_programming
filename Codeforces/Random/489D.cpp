#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

int nC2(int n){
    return ((n*(n-1))/2);
}

void solve(){
    int a,b,n,m;
    cin>>n>>m;
    vector<int> arr[n+1];
    for(int i=0;i<m;i++){
        cin>>a>>b;
        arr[a].push_back(b);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        map<int,int> mp;
        for(int j:arr[i]){
            for(int k:arr[j]){
                mp[k]++;
            }
        }
        for(auto it:mp){
            if(it.first == i) continue;
            if(it.second>1){
                //cout<<"freq of "<<it.first<<" : "<<it.first<<"\n";
                ans += nC2(it.second);
            }
        }
    }
    cout<<ans<<"\n";
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