 #include <bits/stdc++.h>
#define MOD 998244353
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;
    char s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    ll l=1,r=1;
    ll ans = 1;
    for(ll i=1;i<n;i++){
        if(s[i]!=s[i-1])break;
        else l++;
    }
    for(ll i=n-2;i>=0;i--){
        if(s[i]!=s[i+1])break;
        else r++;
    }
    ans = 1 + l + r;
    if(s[0]==s[n-1]){
        ans = (ans + ((l*r + MOD)%MOD) + MOD)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
