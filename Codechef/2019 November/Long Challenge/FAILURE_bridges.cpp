#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

int n,m;
vector<set<int>> adj;

vector<bool> visited;
vector<int> tin, low;
vector<pair<int,int>> saves;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                saves.push_back({v,to});
            }
        }
    }
}

void remove_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    for(pair<int,int> i: saves){
        adj[i.first].erase(i.second);
        adj[i.second].erase(i.first);
    }
}

////////////////////////////////////////

vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs2(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs2(u))
                return true;
        } else if ( u != parent[v] && color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool find_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs2(v))
            break;
    }
    if (cycle_start == -1) {
        return false;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
        return true;
    }
}

void solve(){
    int a,b;
    cin>>n>>m;
    adj.resize(n);
    for(int i=0;i<n;i++){
        adj[i].clear();
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--; b--;
        adj[b].insert(a);
        adj[a].insert(b);
    }
    remove_bridges();
    
    for(int i=0;i<n;i++){
        cout<<i<<": ";
        for(int j:adj[i]){
            cout<<j<<" ";
        } 
        cout<<"\n";
    }

    if(!find_cycle()){
        cout<<"-1\n";
        return;
    }

    int maxx=0;
    for(int i=1;i<n;i++){
        if(adj[i].size()>adj[maxx].size()){
            maxx=i;
        }
    }

    for(int i:adj[maxx]){
        adj[i].erase(maxx);
    }
    adj[maxx].clear();

    cout<<"maxx: "<<maxx<<"\n";
    for(int i=0;i<n;i++){
        cout<<i<<": ";
        for(int j:adj[i]){
            cout<<j<<" ";
        } 
        cout<<"\n";
    }

    if(find_cycle()){
        cout<<"-1\n";
    }
    else{
        cout<<maxx+1<<"\n";
    }
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}