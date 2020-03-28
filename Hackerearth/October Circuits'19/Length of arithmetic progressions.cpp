#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int n,q,prevd = INF, d=0;
    cin>>n>>q;
    map<int,vector<pair<int,int>>> freq;
    int arr[n];
    int l=0,r=0;
    cin>>arr[0];
    for(int i=1;i<n;i++){
        cin>>arr[i];
        r++;
        d = arr[i]-arr[i-1];
        if(d==prevd){
            
        }
        else{
            //cout<<prevd<<"\n";
            if(i!=1)freq[prevd].push_back(make_pair(l,r-1));
            r = i;
            l = i-1;
        }
        prevd = d;
    }
    freq[d].push_back(make_pair(l,r));
    // for(auto i: freq){
    //     cout<<i.first<<" : ";
    //     for(auto j: i.second){
    //         cout<<j.first<<" "<<j.second<<"\t";
    //     }
    //     cout<<"\n";
    // }
    while(q--){
        cin>>l>>r>>d;
        l--; r--;
        int ans=1;
        for(pair<int,int> i: freq[d]){
            ans = max( ans, max(0LL, min(i.second, r) - max(i.first, l) + 1LL ));
        }
        cout<<ans<<"\n";
    }
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