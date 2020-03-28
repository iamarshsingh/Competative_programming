#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

int ans;

int dfs(vector<int> arr[], vector<bool> &visited, int node){
    visited[node] = true;
    int h1=0,h2=0;
    for(int i:arr[node]){
        if(!visited[i]){
            int curr = dfs(arr, visited, i);
            if(curr>h1){
                h2 = h1;
                h1 = curr;
            }
            else if(curr>h2){
                h2 = curr;
            }
        }
    }
    ans = max(ans, h1+h2);
    return h1+1;
}

void solve(){
    int n,a,b;
    cin>>n;
    vector<int> arr[n+1];
    for(int i=1;i<n;i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    ans = 0;
    vector<bool> visited(n+1, false);
    dfs(arr, visited, 1);
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