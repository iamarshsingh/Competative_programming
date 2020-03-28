#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

vector<int> sieve(int n){
    vector<int> ans;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1)
        ans.push_back(n);
    return ans;
}

void solve(){
    int n,sum=0;
    cin>>n;
    int arr[n];
    vector<int> s(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
        s[i] = sum;
    }
    if(sum==1){
        cout<<"-1\n";
        return;
    }
    vector<int> factors = sieve(sum);
    //cout<<factors.size()<<"\n";
    int ans = INF;
    for(int p:factors){
        vector<int> curr(s);
        int c=0;
        for(int i=0;i<n;i++){
            c += min(curr[i]%p, p-(curr[i]%p));
        }
        //cout<<p<<" "<<c<<"\n";
        ans = min(ans, c);
    }
    cout<<ans<<"\n";
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}