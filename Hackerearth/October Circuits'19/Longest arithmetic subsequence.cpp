#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

vector<int> solve2(int n, int k){
    vector<int> ans(n);

}

void solve(){
    int n,k;
    cin>>n>>k;
    if(k==1){
        if(n==1){
            cout<<"Yes\n";
            cout<<"1\n";
        }
        else{
            cout<<"No\n";
        }
    } else{
        if(k<=(n/2)){
            cout<<"Yes"<<"\n";
        }
        else{
            while(true);
        }
    }
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}