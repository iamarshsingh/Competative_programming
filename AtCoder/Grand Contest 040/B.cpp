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
    int ans=0;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        cin>>a>>b;
        ans = max(ans, b-a+1);
        arr[i] = {a,b};
    }
    sort(arr,arr+n);
    stack<int> minR;
    minR.push(arr[n-1].second);
    int l2 = arr[n-1].first;

    for(int j=n-2;j>0;j--){
        if(minR.top()>=arr[j].second){
            minR.push(arr[j].second);
        }
    }

    // for(int i=0;i<n;i++){
    //     cout<<arr[i].first<<" "<<arr[i].second<<"\n";
    // }

    int l1=arr[0].first,r1=arr[0].second;
    ans = max(ans, max(r1-l1+1, 0LL) + max(0LL, (int)minR.top()-l2+1));
    //cout<<ans<<"\n";
    for(int i=1;i<n-1;i++){
        if(!minR.empty() && arr[i].second==minR.top()){
            minR.pop();
        }
        ans = max(ans, max(0LL, min(r1,minR.top()) - max(l1,l2) + 1LL ) + arr[i].second - arr[i].first + 1LL);
        r1 = min(r1, arr[i].second);
        l1 = max(l1, arr[i].first);
        ans = max( ans, max(0LL, r1-l1+1) + max(0LL, (int)minR.top()-l2+1) );
        //cout<<ans<<"\n";
    }
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