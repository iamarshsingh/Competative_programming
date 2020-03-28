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
    string s,t;
    cin>>s>>t;
    vector<int> diff;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            diff.push_back(i);
        }
    }
    if(diff.size()==2){
        int i=diff[0];
        int j=diff[1];
        if(t[i]==t[j] && s[i]==s[j]){
            cout<<"Yes"<<"\n";
        }
        else{
            cout<<"No\n";
        }
    }
    else{
        cout<<"No"<<"\n";
    }
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}