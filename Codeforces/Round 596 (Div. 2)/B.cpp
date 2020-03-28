#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int n,k,d; cin>>n>>k>>d;
    int arr[n];
    int minn=d;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<(n-d+1);i++){
        set<int> s;
        for(int j=i; j<(i+d);j++){
            s.insert(arr[j]);
        }
        minn = min(minn, (int)s.size());
    }
    cout<<minn<<"\n";
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