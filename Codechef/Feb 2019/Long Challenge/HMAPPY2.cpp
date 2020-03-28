#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return ((a*b)/gcd(a,b));
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,a,b,k;
        cin>>n>>a>>b>>k;
        ll ans = ((n/a)+(n/b)-(2*(n/lcm(a,b))));
        //cout<<ans<<endl;
        if(ans>=k)cout<<"Win"<<endl;
        else cout<<"Lose"<<endl;
    }
    return 0;
}
