#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int n,k,p;
    cin>>n>>k>>p;
    int arr[n];
    int maxx=0,minn=INF;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxx = max(maxx, arr[i]);
        minn = min(minn, arr[i]);
    }
    if(p==0 && k%2==1){
        cout<<maxx<<"\n";
    }
    else if(p==1 && k%2==1){
        cout<<minn<<"\n";
    }
    else{
        if(p==0){
            maxx = max(arr[1], arr[n-2]);
            for(int i=1;i<n-1;i++){
                maxx = max(maxx, min(arr[i-1], arr[i+1]));
            }
            cout<<maxx<<"\n";
        }
        else{
            minn = min(arr[1], arr[n-2]);
            for(int i=1;i<n-1;i++){
                minn = min(minn, max(arr[i-1], arr[i+1]));
            }
            cout<<minn<<"\n";
        }
    }
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