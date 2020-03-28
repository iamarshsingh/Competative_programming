#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

bool comp1(pair<int,int> a, pair<int,int> b){
    if(a.first>b.first){
        return true;
    }
    else if(a.first==b.first){
        return a.second<b.second;
    }
    return false;
}

bool comp2(pair<int,int> a, pair<int,int> b){
    if(a.second<b.second) return true;
    return false;
}

bool comp3(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    if(a.second < b.second) return true;
    return false;
}

void solve(){
    int n,q;
    cin>>n;
    pair<int,int> arr[n];
    int fixed[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        fixed[i] = arr[i].first;
        arr[i].second=i;
    }
    
    cin>>q;
    pair<int,pair<int,int>> queries[q];
    for(int i=0;i<q;i++){
        int k,p;
        cin>>k>>p;
        queries[i] = {i, {k, p}};
    }
    sort(queries, queries+q, comp3);

    pair<int,int> ans[q];

    sort(arr, arr+n, comp1);
    int j=0;
    ordered_set oset;
    for(int i=1;i<=n;i++){
        int curr = arr[i-1].second;
        oset.insert(curr);
        while(queries[j].second.first <= i){
            //cout<<i<<" "<<j<<" "<<queries[j].second.first<<" "<<queries[j].second.second-1<<" "<<*(oset.find_by_order(queries[j].second.second-1))<<"\n";
            ans[j] = {queries[j].first, fixed[*(oset.find_by_order(queries[j].second.second-1))] };
            j++;
        }
        //cout<<i<<" done"<<"\n";
    }

    sort(ans, ans+q);
    
    for(int i=0;i<q;i++){
        cout<<ans[i].second<<"\n";
    }

}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}