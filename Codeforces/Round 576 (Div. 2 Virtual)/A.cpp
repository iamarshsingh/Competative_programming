#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        bool poss=true;
        for(int j=i-1;j>=max(0LL,i-x);j--){
            if(arr[j]<arr[i]){
                poss=false;
                break;
            }
        }
        for(int j=i+1;j<=min(n-1,i+y);j++){
            if(arr[j]<arr[i]){
                poss=false;
                break;
            }
        }
        //cout<<i<<" "<<poss<<endl;
        if(poss){
            cout<<i+1<<"\n";
            return;
        }
    }
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