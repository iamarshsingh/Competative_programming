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
    int n;
    cin>>n;
    int sq = (int)sqrt(n);
    set<int> s;
    s.insert(0);
    for(int i=1;i<=sq;i++){
        s.insert(i);
        s.insert((n/i));
    }
    cout<<s.size()<<"\n";
    for(int i:s){
        cout<<i<<" ";
    }
    cout<<"\n";
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}