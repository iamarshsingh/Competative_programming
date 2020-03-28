#include <bits/stdc++.h>
#define MOD 998244353
#define ll long long int
using namespace std;

int main(){
    ll n;
    cin>>n;
    ll ans = 1;
    for(ll i=2;i<n;i++){
        ans = (ans + (i*i))%MOD;
    }
    ans = (ans*n)%MOD;
    cout<<ans<<endl;
    return 0;
}
