#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000
using namespace std;

int a,b;

int cost(pair<int,int> p1){
    return (p1.first*a + p1.second*b);
}

bool comp(pair<int,int> p1, pair<int,int> p2){
    return (p1.first*a + p1.second*b) < (p2.first*a+p2.second*b);
}

// struct compar{
//     bool operator()(const pair<int,int> &p1, const pair<int,int> &p2){
//         return (p1.first*a + p1.second*b) < (p2.first*a+p2.second*b);
//     }
// };

void solve(){
    int n,m;
    cin>>n>>m>>a>>b;
    
    int f,e;
    vector<pair<int,int>> arr[n+1];
    int T[m], C[m], H[m];
    for(int i=0;i<m;i++){
        cin>>f>>e>>T[i]>>C[i]>>H[i];
        arr[f].push_back(make_pair(e,i));
    }

    queue<int> q;
    q.push(1);
    //time, cost
    vector<pair<int,int>> dp(n+1, make_pair(INF,INF));
    vector<pair<int,int>> par(n+1);
    dp[1] = {0,0};
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        int curtime = dp[temp].first;
        int cost = dp[temp].second;
        for(pair<int,int> i: arr[temp]){
            int reachtime = (curtime==0) ? 0 : ((curtime%H[i.second] == 0) ? curtime : (curtime - curtime%H[i.second] + H[i.second]));
            reachtime += T[i.second];
            if(comp(make_pair(reachtime, cost + C[i.second]), dp[i.first])){
                dp[i.first] = make_pair(reachtime, cost + C[i.second]);
                q.push(i.first);
                par[i.first] = {temp, i.second};
            }
        }
    }
    deque<int> ans;
    int i=n;
    while(i!=1){
        //cout<<i<<endl;
        pair<int,int> prev = par[i];
        i = prev.first;
        ans.push_front(prev.second+1);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    //cout<<(cost(dp[n]))<<"\n";
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