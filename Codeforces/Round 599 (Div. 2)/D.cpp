#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
 
bool comp(pair<int, set<int>> a, pair<int, set<int>> b){
    return a.second.size()<b.second.size();
}

void dfs(set<int> adj[], vector<bool> &visited, int node){
    visited[node] = true;
    for(int j: adj[node]){
        if(!visited[j]){
            dfs(adj, visited, j);
        }
    }
}

void solve(){
    int a,b,n,m;
    cin>>n>>m;
    if(n<=1000){
        set<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                adj[i].insert(j);
                adj[j].insert(i);
            }
        }
        for(int i=0;i<m;i++){
            cin>>a>>b;
            adj[a-1].erase(b-1);
            adj[b-1].erase(a-1);
        }
        int ans=-1;
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(adj, visited, i);
            }
        }
        cout<<ans<<'\n';
        return;
    }
    vector<pair<int, set<int>>> adj(n);
    for(int i=0;i<n;i++){
        adj[i].first = i;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a-1].second.insert(b-1);
        adj[b-1].second.insert(a-1);
    }
    sort(adj.begin(), adj.end(), comp);
    int ans=0;
    set<int> curr = adj[0].second;
    set<int> temp;
    for(int i=1;i<n;i++){
        if(curr.find(adj[i].first)!=curr.end()){
            ans++;
            //cout<<"i: "<<i<<"\n";
        }
        temp.clear();
        for(int j:adj[i].second){
            if(curr.find(j)!=curr.end()){
                temp.insert(j);
                //cout<<j<<" ";
            }
        }
        //cout<<'\n';
        curr = temp;
    }
    cout<<ans<<"\n";
}
 
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}