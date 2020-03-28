#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 10000007
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NUint);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

int fact[N];

int power(int a, int b, int p){
    int ans = 1;
    while (b > 0) 
    {
        if (b & 1) 
            ans = (ans*a)%p;
        
        b = b>>1;
        a = (a*a)%p;
    }
    return ans;
}

int inv(int a, int p){
    return power(a,p-2,p);
}

int preComp(int p){
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1] * i)%p;
    }
}

int nCr(int n, int r, int p){
    return ( (fact[n]*inv(fact[r], MOD)%p * inv(fact[n-r], MOD) ) ) % p;
}

void solve(){
    int x,y,n,m,i,j;
    cin>>x>>y;
    n=max(x,y);
    m=min(x,y);
    if((x+y)%3!=0){
        cout<<"0\n";
        return;
    }
    pair<int,int> ans;
    int maxx=0;
    for(i=0;i<=m;i++){
        j=(m-i);
        if(j%2==0){
            j/=2;
            if(j+(2*i) == n){
                ans = {i,j};
                maxx = max(maxx, ((fact[ans.first+ans.second] * inv(fact[ans.first], MOD))%MOD * inv(fact[ans.second], MOD))%MOD);
            }
        }
    }
    cout<<maxx<<'\n';
}

signed main(){
    preComp(MOD);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}