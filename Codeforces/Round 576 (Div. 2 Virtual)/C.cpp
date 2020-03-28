#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

void solve(){
    int n,I;
    cin>>n>>I;
    int arr[n];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    if(((8*I)/n) > 20){
        cout<<0<<endl;
        return;
    }
    int maxu = 1LL<<((8*I)/n);
    int s = mp.size();
    int ans = n;
    vector<int> freq(s+1,0);
    int i=1;
    for(auto it:mp){
        freq[i] = freq[i-1] + it.second;
        i++;
    }
    for(i=1;i<=s;i++){
        ans = min(ans, n - (freq[min(s,i+maxu-1)]-freq[i-1]));
    }
    cout<<ans<<endl;
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