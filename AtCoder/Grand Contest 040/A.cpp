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
    int ans=0,curr=0,prev=0;
    char c = s[0];
    for(int i=0;i<n;i++){
        if(s[i]==c){
            curr++;
            if(i==n-1){
                if(c=='>'){
                    if(curr>prev) ans += (curr-prev);
                    ans += (curr*(curr-1))/2;
                }
                else{
                    ans += (curr*(curr+1))/2;
                }
            }
        }
        else{
            if(c=='>'){
                if(curr>prev) ans += (curr-prev);
                ans += (curr*(curr-1))/2;
            }
            else{
                ans += (curr*(curr+1))/2;
            }
            prev=curr;
            curr=1;
            c=s[i];
            if(i==n-1 && c=='<'){
                ans++;
            }
        }
        //cout<<ans<<" ";
    }
    cout<<ans<<"\n";
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