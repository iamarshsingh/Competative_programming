#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

void solve(){
    int n;
    cin>>n;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].second;
        arr[i].first = 0;
    }
    int q,t,a,b;
    cin>>q;
    vector<int> saved(q+1,0);
    for(int i=1;i<=q;i++){
        cin>>t;
        if(t==1){
            cin>>a>>b;
            arr[a-1] = {i,b};
        }
        else if(t==2){
            cin>>a;
            saved[i] = a;
        }
    }
    for(int i=q-1;i>=0;i--){
        saved[i] = max(saved[i+1], saved[i]);
    }
    for(int i=0;i<n;i++){
        cout<<(max(arr[i].second, saved[arr[i].first]))<<" ";
    }
    cout<<"\n";
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