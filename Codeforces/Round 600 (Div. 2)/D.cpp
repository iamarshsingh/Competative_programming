#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
//int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

void dfs(vector<int> adj[], vector<int> &visited, int node, int par, int &maxx){
    visited[node] = par;
    maxx = max(maxx, node);
    for(int i:adj[node]){
        if(visited[i] == -1){
            dfs(adj, visited, i, par, maxx);
        }
    }
}

void solve(){
    int a,b,n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        cin>>a>>b;
        //cout<<a<<" "<<b<<"\n";
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> visited(n+1,-1);
    int ans=0;
    for(int i=1;i<=n;i++){
        int maxx=i;
        // cout<<i<<" "<<visited[i]<<" "<<maxx<<"\n";
        if(visited[i]==-1)
            dfs(adj, visited, i, i, maxx);
        // cout<<i<<" "<<maxx<<"\n";
        int j=i+1;
        while(j<=maxx){
            if(visited[j]==-1){
                ans++;
                dfs(adj, visited, j, i, maxx);
            }
            j++;
        }
        // cout<<i<<" "<<j<<" "<<maxx<<"\n";
        i=j-1;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<visited[i]<<" ";
    // }
    // cout<<"\n";
    cout<<ans<<"\n";
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}