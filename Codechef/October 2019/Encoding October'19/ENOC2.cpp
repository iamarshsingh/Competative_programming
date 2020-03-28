#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int a,b=2,c;
    cin>>a>>c;
    while(a<c){
        if((c-a) % b == 0){
            cout<<"YES"<<"\n";
            return;
        }
        a = a*2;
    }
    cout<<"NO"<<"\n";
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