#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define pr pair<ll,ll>
using namespace std;


int main(){
    ll n;
    long double l,r;
    cin>>n>>l>>r;
    ll zero=0,one=0,two=0;
    zero = floor(r/3)-ceil(l/3)+1;
    one = floor((r-1)/3)-ceil((l-1)/3)+1;
    two = floor((r-2)/3)-ceil((l-2)/3)+1;
    ll dp[n+1][3];
    dp[1][0]=zero;dp[1][1]=one;dp[1][2]=two;
    //cout<<dp[1][0]<<dp[1][1]<<dp[1][2]<<endl;
    for(int i=2;i<=n;i++){
        dp[i][0] = ( ( (dp[i-1][2]*one)%MOD + (dp[i-1][1]*two)%MOD)%MOD + (dp[i-1][0]*zero)%MOD )%MOD;
        dp[i][1] = ( ( (dp[i-1][1]*zero)%MOD + (dp[i-1][0]*one)%MOD)%MOD + (dp[i-1][2]*two)%MOD )%MOD;
        dp[i][2] = ( (dp[i-1][1]*one)%MOD + (dp[i-1][0]*two)%MOD + (dp[i-1][2]*zero)%MOD )%MOD;
    }
    cout<<dp[n][0]<<endl;
}
