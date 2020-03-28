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
    int a,b;
    cin>>a>>b;
    int m = max(a,b);
    int s = min(a,b);
    int diff = m-s;
    if(diff==0 || diff==1 ) cout<<diff<<"\n";
    else{
        int r = (int)sqrt(diff);
        r++;
        while(((r*(r+1))/2)<diff) r++;
        int l = ((r*(r+1))/2)-diff;
        while( l%2==1 ){
            r++;
            l = ((r*(r+1))/2)-diff;
        }
        cout<<r<<"\n";
    
    }
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}