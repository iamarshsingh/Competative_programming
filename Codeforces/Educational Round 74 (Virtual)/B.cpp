#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int a,n,r,ans=0,curl=0;
    cin>>n>>r;
    set<int, greater<int>> s; 
    for(int i=0;i<n;i++){
        cin>>a;
        s.insert(a);
    }
    for(int i:s){
        if(i-curl>0){
            ans++;
            curl += r;
        }
        else{
            break;
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}