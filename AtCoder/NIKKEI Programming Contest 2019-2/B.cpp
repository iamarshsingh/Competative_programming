#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 998244353
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

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

void solve(){
    int n,maxx=0,ans=1,a,c=1;
    cin>>n;
    int arr[n];
    vector<int> freq(n,0);
    bool poss=false;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
        maxx=max(maxx, arr[i]);
        if(i>0 && arr[i]==0) poss=true;
    }
    if(arr[0]!=0 || poss){
        cout<<0<<"\n";
        return;
    }
    for(int i=1;i<=maxx;i++){
        if(freq[i]==0){
            ans=0;
            break;
        }
        ans = (ans * power(freq[i-1], freq[i], MOD))%MOD;
        //cout<<ans<<"\n";
    }
    cout<<ans<<"\n";
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}