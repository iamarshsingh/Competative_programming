#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

int power(int a, int b, int p){
    int ans = 1LL;
    while (b > 0LL) 
    {
        if (b & 1LL) 
            ans = (ans*a)%p; 
        
        b = b>>1;
        a = (a*a)%p;
    }
    return ans; 
}

int inv(int a){
    return power(a,MOD-2,MOD);
}

int fact[N];
int ifact[N];
int po2[N];

int preComp(int p){
    fact[0] = 1;
    po2[0] = 1;
    ifact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1] * i)%p;
        ifact[i] = (ifact[i-1] * inv(i))%p;
        po2[i] = (po2[i-1] * 2LL)%MOD;
    }
}

int nCr(int n, int r, int p){
    return ( (fact[n]*ifact[r])%p * ifact[n-r] )  % p;
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int ans[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        ans[i] = 0;
        for(int j=i;j<n;j++){
            ans[i] = ( ans[i] + ( (arr[j] * po2[n-j-1])%MOD * nCr(j,i,MOD) )%MOD )%MOD;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    preComp(MOD);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}