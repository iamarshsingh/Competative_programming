#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

vector<int> cur_child;

void dfs_cycle2(int u, int p, set<int> adj[], vector<int> &color, vector<int> &mark, vector<int> &par, int& cyclenumber){

    if (color[u] == 2) { 
        return; 
    }
  
    if (color[u] == 1) { 
  
        cyclenumber++; 
        int cur = p; 
        mark[cur] = cyclenumber; 

        while (cur != u) { 
            cur = par[cur]; 
            mark[cur] = cyclenumber; 
        } 
        return; 
    }
    par[u] = p; 
  
    color[u] = 1; 
  
    for (int v : adj[u]) { 
  
        if (v == par[u]) { 
            continue; 
        } 
        dfs_cycle2(v, u, adj, color, mark, par, cyclenumber); 
    } 
  
    color[u] = 2;
}

void dfs_cycle(int u, int p, set<int> adj[], vector<int> &color, vector<int> &mark, vector<int> &par, int& cyclenumber){

    if (color[u] == 2) { 
        return; 
    }
  
    if (color[u] == 1) { 
  
        cyclenumber++; 
        int cur = p; 
        mark[cur] = cyclenumber; 

        while (cur != u) {
            cur = par[cur];
            if(mark[cur]!=0) break;
            mark[cur] = cyclenumber; 
        }

        cur = u;
        mark[cur] = cyclenumber;

        while(mark[cur]==0){
            cur = cur_child[cur]; 
            mark[cur] = cyclenumber;
        }

        return;
    }
    par[u] = p; 
  
    color[u] = 1; 
  
    for (int v : adj[u]) { 
  
        if (v == par[u]) { 
            continue; 
        }
        cur_child[u] = v; 
        dfs_cycle(v, u, adj, color, mark, par, cyclenumber); 
    } 
  
    color[u] = 2;
}

void solve(){

    int n,m,a,b;
    cin>>n>>m;
    set<int> adj[n+1];
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[b].insert(a);
        adj[a].insert(b);
    }
    cur_child.resize(n+1,0);
    vector<int> color(n+1,0);
    vector<int> mark(n+1,0);
    vector<int> par(n+1,0); 
    int cyclenumber=0;

    // for(int i=1;i<=n;i++){
    //     cout<<i<<": ";
    //     for(int j:adj[i]){
    //         cout<<j<<" ";
    //     } 
    //     cout<<"\n";
    // }

    if(n<=1000){
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                dfs_cycle2(i, 0, adj, color, mark, par, cyclenumber);
                //cout<<"IN: "<<i<<" "<<cyclenumber<<"\n";
            }
        }

        if(n==1 && m>0){
            cout<<"1\n";
            return;
        }

        if(cyclenumber==0){
            cout<<"-1\n";
            return;
        }


        bool poss=false;

        for(int i=1;i<=n;i++){
            //cout<<mark[i]<<"\n";
            if(mark[i]==0){
                for(int j:adj[i]){
                    adj[j].erase(i);
                }
                adj[i].clear();
            }
            else poss=true;
        }

        if(!poss){
            cout<<"-1\n";
            return;
        }

        int maxx=0;

        for(int i=1;i<=n;i++){
            if(mark[i]!=0 && adj[i].size()>adj[maxx].size()){
                maxx=i;
            }
        }

        adj[maxx].clear();
        for(int i:adj[maxx]){
            adj[i].erase(maxx);
        }

        color.assign(n+1,0);
        mark.assign(n+1,0);
        par.assign(n+1,0);
        cyclenumber=0;
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                dfs_cycle2(i, 0, adj, color, mark, par, cyclenumber);
                //cout<<"IN: "<<i<<" "<<cyclenumber<<"\n";
            }
        }
        
        if(cyclenumber==0){
            cout<<maxx<<"\n";
        }
        else cout<<"-1"<<"\n";
        return;
    }

    for(int i=1;i<=n;i++){
        if(color[i]==0){
            dfs_cycle(i, 0, adj, color, mark, par, cyclenumber);
            //cout<<"IN: "<<i<<" "<<cyclenumber<<"\n";
        }
    }

    if(n==1 && m>0){
        cout<<"1\n";
        return;
    }

    if(cyclenumber==0){
        cout<<"-1\n";
        return;
    }


    bool poss=false;

    for(int i=1;i<=n;i++){
        //cout<<i<<": "<<mark[i]<<"\n";
        if(mark[i]==0){
            for(int j:adj[i]){
                adj[j].erase(i);
            }
            adj[i].clear();
        }
        else poss=true;
    }

    if(!poss){
        cout<<"-1\n";
        return;
    }

    int maxx=0;

    for(int i=1;i<=n;i++){
        if(mark[i]!=0 && adj[i].size()>adj[maxx].size()){
            maxx=i;
        }
    }

    // cout<<"maxx: "<<maxx<<"\n";
    // for(int i=1;i<=n;i++){
    //     cout<<i<<": ";
    //     for(int j:adj[i]){
    //         cout<<j<<" ";
    //     } 
    //     cout<<"\n";
    // }

    adj[maxx].clear();
    for(int i:adj[maxx]){
        adj[i].erase(maxx);
    }

    color.assign(n+1,0);
    mark.assign(n+1,0);
    par.assign(n+1,0);
    cyclenumber=0;
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            dfs_cycle(i, 0, adj, color, mark, par, cyclenumber);
            //cout<<"IN: "<<i<<" "<<cyclenumber<<"\n";
        }
    }
    
    if(cyclenumber==0){
        cout<<maxx<<"\n";
    }
    else cout<<"-1"<<"\n";
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