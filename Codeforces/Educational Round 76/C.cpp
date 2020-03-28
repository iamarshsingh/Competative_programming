#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> freq(n+1,0);
    int i=0,j=0,ans=n+1;
    while(j<n){
        freq[arr[j]]++;
        if(freq[arr[j]]>1){
            while(i<j && freq[arr[j]]>1){
                freq[arr[i]]--;
                i++;
            }
            ans = min(ans, j-i+1);
        }
        j++;
    }
    if(ans==n+1){
        cout<<-1<<"\n";
    }
    else{
        cout<<ans+1<<"\n";
    }
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}