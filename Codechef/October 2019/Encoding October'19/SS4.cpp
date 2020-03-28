#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int n,a,b;
    cin>>n;
    vector<int> arr[n+1];
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    vector<bool> visited(n+1, false);
    map<int,int> freq;
    queue<pair<int,int>> q;
    int maxx = 1;
    freq[1] = 1;
    q.push({1,1});
    visited[1] = true;
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        for(int i: arr[temp.first]){
            if(!visited[i]){
                q.push({i,temp.second+1});
                freq[temp.second+1]++;
                if(freq[temp.second+1]> freq[maxx]){
                    maxx = temp.second+1;
                }
                visited[i] = true;
            }
        }
    }
    cout<<maxx<<"\n";

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