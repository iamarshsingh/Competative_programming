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
    int a[3];
    for(int i=0;i<3;i++) cin>>a[i];
    sort(a,a+3);
    int ans=0;
    int sum2 = a[0]+a[1];
    if(sum2<=a[2]){
        cout<<sum2<<"\n";
    }
    else{
        cout<<a[2] + (sum2-a[2])/2 <<"\n";
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