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
    char s[n], t[n];
    vector<int> freq(26,0);
    for(int i=0;i<n;i++){
        cin>>s[i];
        freq[s[i]-'a']++;
    }
    for(int i=0;i<n;i++){
        cin>>t[i];
        freq[t[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(freq[i]%2==1){
            cout<<"No\n";
            return;
        }
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        if(s[i]==t[i]) continue;
        bool poss=false;
        for(int j=i+1;j<n;j++){
            if(s[j]==s[i]){
                ans.push_back({j,i});
                s[j]=t[i];
                t[i]=s[i];
                poss=true;
                break;
            }
        }
        if(poss) continue;
        for(int j=i+1;j<n;j++){
            if(s[i]==t[j]){
                ans.push_back({i,i});
                ans.push_back({i,j});
                t[j] = t[i];
                t[i] = s[i];
            }
        }
    }
    cout<<"Yes\n";
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
    }
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}