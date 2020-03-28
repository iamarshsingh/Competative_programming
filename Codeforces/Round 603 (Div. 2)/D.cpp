#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

void dfs(set<int> adj[], vector<bool> &visited, int node){
    visited[node] = true;
    for(int i: adj[node]){
        if(!visited[i]){
            dfs(adj, visited, i);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    string s[n];
    set<int> adj[26];
    vector<bool> cont(26,false);
    vector<bool> visited(26,false);
    for(int i=0;i<n;i++){
        cin>>s[i];
        cont[(s[i][0]-'a')] = true;
        for(int j=1;j<s[i].length();j++){
            cont[(s[i][j]-'a')] = true;
            adj[(s[i][0]-'a')].insert(s[i][j]-'a');
            adj[s[i][j]-'a'].insert(s[i][0]-'a');
        }
    }
    int ans=0;
    for(int i=0;i<26;i++){
        if(cont[i]==true && visited[i]==false){
            ans++;
            dfs(adj, visited, i);
        }
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