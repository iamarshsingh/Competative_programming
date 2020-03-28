#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    if(n==1){
        cout<<s<<"\n";
        return;
    }
    int ans[n];
    for(int i=0;i<n-1;i++){
        ans[i] = ( (s[i]-'0') ^ (s[i+1]-'0') ); 
    }
    ans[n-1] = ( (s[0]-'0') ^ (s[n-1]-'0') );
    for(int i=0;i<n;i++){
        cout<<ans[i]; 
    }
    cout<<"\n";
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}