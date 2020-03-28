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
    int n;
    cin>>n;
    int arr[n];
    int l,r;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1){
            l=r=i;
        }
    }
    vector<int> ans(n,0);
    ans[0] = 1;
    int maxx=1,curr=1;
    while(l>0 || r<n-1){
        if(l>0 && r<n-1){
            if(arr[l-1]>arr[r+1]){
                r++;
                maxx = max(maxx, arr[r]);
            }
            else{
                l--;
                maxx = max(maxx, arr[l]);
            }
        }
        else if(l>0){
            l--;
            maxx = max(maxx, arr[l]);
        }
        else if(r<n-1){
            r++;
            maxx = max(maxx, arr[r]);
        }
        curr++;
        if(curr==maxx){
            ans[curr-1]=1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    cout<<"\n";
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}