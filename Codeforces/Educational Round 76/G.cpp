//https://codeforces.com/contest/1257/problem/G

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
    int n,a;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++){
        cin>>a;
        s.insert(a);
    }
    cout<<((s.size()*(s.size()-1))/2)<<"\n";
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}