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

void solve(){
    int n,m,a;
    cin>>n>>m;
    
    int arr[n];
    set<int> present;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        present.insert(arr[i]);
    }
    
    sort(arr, arr+n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++){
        if( present.find(arr[i]-1) == present.end() ) pq.push({1, arr[i]-1});
        if( present.find(arr[i]+1) == present.end() ) pq.push({1, arr[i]+1});
    }
    int ans=0;
    vector<int> mm;
    while(m>0){
        pair<int,int> curr = pq.top();
        pq.pop();
        if(present.find(curr.second) != present.end() ) continue;
        ans += curr.first;
        m--;
        present.insert(curr.second);
        mm.push_back(curr.second);
        if( present.find(curr.second-1) == present.end() ) pq.push({curr.first+1, curr.second-1});
        if( present.find(curr.second+1) == present.end() ) pq.push({curr.first+1, curr.second+1});
    }
    cout<<ans<<"\n";
    for(int i=0;i<mm.size();i++){
        cout<<mm[i]<<" ";
    }
    cout<<"\n";
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}