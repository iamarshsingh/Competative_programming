#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int n, h, duck, jump, p;
    cin>>n>>h>>duck>>jump>>p;
    int ans=0;
    int t[n], a[n];
    for(int i=0;i<n;i++){
        cin>>t[i]>>a[i];
    }
    int i;
    for(i=0;i<n;i++){
        if(t[i]==1){
            if(h-duck > a[i]){
                p--;
            }
        }
        else{
            if(jump < a[i]){
                p--;
            }
        }
        //cout<<"p: "<<p<<"\n";
        if(p==0) break;
        ans++;
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