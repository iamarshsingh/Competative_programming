#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

void solve(){
    int n,a,b;
    cin>>n;
    int k = n;
    int ans=0;
    vector<int> vminn;
    vector<int> vmaxx;
    for(int i=0;i<n;i++){
        cin>>a;
        int minn = MOD;
        int maxx=-1;
        bool poss=false;
        while(a--){
            cin>>b;
            if(!poss && b>minn){
                ans += ((2*(k-1)) + 1);
                k--;
                poss=true;
            }
            minn = min(minn,b);
            maxx = max(maxx,b);
        }
        if(!poss){
            vminn.push_back(minn);
            vmaxx.push_back(maxx);
        }
    }
    //cout<<ans<<"\n";
    sort(vminn.begin(), vminn.end());
    sort(vmaxx.begin(), vmaxx.end());   

    // for(int i:vminn) cout<<i<<" ";
    // cout<<"\n";

    for(int i:vmaxx){
       //// cout<<i<<" ";
        ans += (int)(lower_bound(vminn.begin(), vminn.end(), i) - vminn.begin());
      //  cout<<ans<<"\n";
    }
    cout<<ans<<"\n";
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}