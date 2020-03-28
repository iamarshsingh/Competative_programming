#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

void solve(){
    int a,b,c;
    while(true){
        cin>>a>>b>>c;
        if(a==b && b==c && a==0){
            break;
        }
        if((2*b)==(a+c)){
            cout<<"AP "<<(c+(c-b))<<"\n";
        }
        else{
            cout<<"GP "<<(c*(c/b))<<"\n";
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