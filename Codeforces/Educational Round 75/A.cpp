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
    vector<bool> poss(26,false);
    for(int i=0;i<s.length();i++){
        if(i<(s.length()-1) && s[i]==s[i+1]){
            i++;
        }
        else{
            poss[s[i]-'a'] = true;
        }
    }
    for(int i=0;i<26;i++){
        if(poss[i]) cout<<string(1, 'a'+i);
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