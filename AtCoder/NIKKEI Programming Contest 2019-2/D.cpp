#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000LL
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

bool comp(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b){
    if(a.first == b.first) return a.second<b.second;
    else return a.first<b.first;
}

void solve(){
    int n,m;
    cin>>n>>m;
    pair<pair<int,int>, int> arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second;
    }
    sort(arr, arr+m, comp);
    vector<int> dp(n+1,INF);
    dp[1] = 0;
    int i=0,d=1,base=0,maxx=1,omaxx=1;
    while(i<m){
        d=maxx;
        maxx=0;
        while(i<m && arr[i].first.first<=d){
            // cout<<"passed: "<<arr[i].first.first<<" "<<arr[i].first.second<<" "<<arr[i].second<<"\n";
            dp[arr[i].first.second] = min(dp[arr[i].first.second], dp[arr[i].first.first] + arr[i].second);
            maxx = max(maxx, arr[i].first.second);
            i++;
        }
        omaxx=max(maxx, omaxx);
        if(i<m && omaxx<arr[i].first.first) break;
        int minn=maxx;
        for(int j=maxx-1; j>d;j--){
            dp[j] = min(dp[j], dp[j+1]);
            if(dp[j]<dp[minn]){
                minn=j;
            }
            // if(dp[j]<dp[j+1]){
            //     k.push_back(j);
            // }
        }
        if(i<m){
            maxx = max(minn, arr[i].first.first);
        }
        else
            break;
        // for(int i=1;i<=n;i++){
        //     cout<<dp[i]<<" ";
        // }
        // cout<<"\n";
    }
    if(dp[n]==INF){
        cout<<"-1\n";
        return;
    }
    cout<<dp[n]<<"\n";
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}