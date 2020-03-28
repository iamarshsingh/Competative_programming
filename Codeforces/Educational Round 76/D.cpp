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
    cin>>n;
    int mon[n];
    for(int i=0;i<n;i++){
        cin>>mon[i];
    }
    cin>>m;
    vector<pair<int,int>> heros(m);
    for(int i=0;i<m;i++){
        cin>>heros[i].first>>heros[i].second;
    }
    sort(heros.begin(), heros.end());
    map<int,int> mp;
    mp[heros[m-1].first] = heros[m-1].second;
    for(int i=m-2;i>=0;i--){
        heros[i].second = max(heros[i].second, heros[i+1].second);
        mp[heros[i].first] = heros[i].second;
    }
    int ans=0,curr=0,cov=0,i=0;
    while(i<n){
        //cout<<i<<endl;
        curr=mon[i];
        if(mp.lower_bound(curr)==mp.end()){
            ans=-1;
            break;
        }
        cov=1;
        i++;
        //cout<<"heel: "<<curr<<" : "<<(*mp.lower_bound(curr)).first<<"\n";
        
        while( ( i<n && mp.lower_bound(max(curr, mon[i]))!=mp.end() ) && (++cov)<=(*mp.lower_bound(max(curr, mon[i]))).second ){
            curr = max(curr, mon[i]);
            //cout<<curr<<" : "<<(*mp.lower_bound(curr)).first<<"  "<<(*mp.lower_bound(curr)).second<<"\n";
            i++;
        }

        ans++;
    }
    cout<<ans<<"\n";
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}