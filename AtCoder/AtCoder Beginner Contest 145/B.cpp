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
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2==1){
        cout<<"No\n";
        return;
    }
    string a = s.substr(0,(n/2));
    string b = s.substr((n/2), (n/2));
    if(a==b){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}