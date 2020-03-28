#include <bits/stdc++.h>
#define MOD 998244353
#define ll long long
using namespace std;

int color[300005];
bool visited[300005];
vector<int> grp[300005];
ll odd = 0;
ll even = 0;

bool dfs(vector<int> grp[300005], ll v){
    if(color[v]==0)odd++;
    else even++;
    visited[v] = true;
    for (int u : grp[v]) {
        if (visited[u] == false) {
            color[u] = !color[v];
            if (!dfs(grp, u))
                return false;
        }
        else if (color[u] == color[v])
            return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;

    ll pw[300005];
    pw[0]=1;
    pw[1]=2;
    for(ll i=2;i<300005;i++){
        pw[i] = (pw[i-1]*2)%MOD;
    }

    while(t--){
        int n,m,a,b;
        cin>>n>>m;
        for(int i=0;i<300005;i++){
            grp[i].clear();
            color[i]=-1;
            visited[i]=false;
        }
        for(int i=0;i<m;i++){
            cin>>a>>b;
            grp[a-1].push_back(b-1);
            grp[b-1].push_back(a-1);
        }

        ll ans = 1;

        for(int i=0;i<n;i++){
            if(!visited[i]){

                visited[i] = true;
                color[i] = 0;
                odd=0;
		        even=0;
                if(!dfs(grp,i)) ans = 0;
                ans = (ans*(pw[odd] + pw[even]))%MOD;
            }
        }

        cout<<ans<<endl;

    }
    return 0;
}
