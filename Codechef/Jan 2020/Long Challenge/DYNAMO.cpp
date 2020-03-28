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
    int n,a,b,d,s;
    cin>>n;
    cin>>a;
    s=1;
    for(int i=0;i<n;i++) s=s*10;
    int temp = s;
    s = (2*s)+a;
    cout<<s<<endl;
    cin>>b;
    cout<<(temp-b)<<endl;
    cin>>d;
    cout<<(temp-d)<<endl;
    cin>>n;
    return;
}

signed main(){
    //fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}