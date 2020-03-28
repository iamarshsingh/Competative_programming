#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

ll power(ll a, ll b){
    if(b == 0) return 1;
    ll ans = power(a,b/2)%MOD;
    if(b%2==0) return (ans*ans)%MOD;
    else return ((ans*ans)%MOD * a)%MOD;
}

ll modInv(ll a){
    return power(a, MOD-2);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k,m;
        cin>>n>>k>>m;
        //cout<<(modInv(56))<<endl;
        if(m%2==0){
            ll one = (m/2);
            ll num = (((n+k)*(power(n,one)-power(n-1,one)))%MOD + power(n-1,one) + MOD)%MOD;
            ll den = (((n+k)*(power(n,one)))%MOD + MOD)%MOD;
            //cout<<num<<endl;
            //cout<<den<<endl;
            ll gc = (gcd(num,den));
            num = num / gc;
            den = den / gc;
            //cout<<num<<endl;
            //cout<<den<<endl;
            ll ans = ((num * modInv(den))%MOD + MOD)%MOD;
            //cout<<one<<" "<<(power(n,one)-power(n-1,one))<<" "<<power(n,one)<<endl;
            cout<<ans<<endl;
        }
        else{
            ll one = (m/2)+1;
            //cout<<one<<endl;
            ll ans = (((power(n,one)-power(n-1,one)+MOD)%MOD)*modInv(power(n,one)))%MOD;
            cout<<ans<<endl;
        }
    }
    return 0;
}
