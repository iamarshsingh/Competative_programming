#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

void solve(){
    string s;
    cin>>s;
    while(s[0]!='0'){
        int prev=0,curr=0;
        vector<int> dp(s.length()+1,0);
        dp[0] = 1;
        for(int i=1;i<=s.length();i++){
            curr = s[i-1]-'0';
            if(i>1 && prev>0){
                prev *=10;
                prev += s[i-1]-'0';
                if(prev>0 && prev<=26)dp[i] += dp[i-2];
            }
            if(curr!=0) dp[i] += dp[i-1];
            prev=curr;
        }
        cout<<dp[s.length()]<<"\n";
        cin>>s;
    }
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}