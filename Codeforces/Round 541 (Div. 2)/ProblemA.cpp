#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll w1,h1,w2,h2;
    cin>>w1>>h1>>w2>>h2;
    ll ans = (w1+w2+4) + ((ll)2)*(h1+h2) + (w1-w2);
    cout<<ans<<endl;
}
