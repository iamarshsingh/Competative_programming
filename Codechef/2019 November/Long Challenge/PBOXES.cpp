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
    int n,x,y;
    cin>>n;
    set<pair<int,int>> b;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        b.insert({x,y});
    }
    int ans=-INF;
    for(int i=0;i<(n/2);i++){
        pair<int,int> base = {-INF,-INF};
        pair<int,int> minn = base;
        pair<int,int> maxx = base;
        pair<int, pair<pair<int,int>, pair<int,int>>> best = {0,{base,base}};
        for(auto j:b){
            if(minn==base){
                minn=j;
            }
            else if(maxx==base){
                maxx=j;
            }
            if(j.second<=minn.second){
                minn=j;
            }
            else if(maxx.second<=j.second || maxx.first<minn.first){
                maxx=j;
            }
            if(minn.first<=maxx.first && maxx.second-minn.second>=best.first){
                best.first = maxx.second-minn.second;
                best.second = {minn,maxx};
            }
        }
        ans = max( max(ans, ans+ best.first), best.first );
        b.erase(best.second.first);
        b.erase(best.second.second);
        cout<<ans<<"\n";
    }
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}