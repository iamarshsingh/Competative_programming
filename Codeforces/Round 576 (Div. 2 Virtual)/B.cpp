#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

void solve(){
    ld h,l,d;
    cin>>h>>l;
    cout<<(((l*l) - (h*h))/(2*h))<<endl;
}

int main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}