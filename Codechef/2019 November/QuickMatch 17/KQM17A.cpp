#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

int fact(int n){
    int ans=1;
    for(int i=2;i<=n;i++){
        ans *= i;
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    string A[n], B[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
        sort(A[i].begin(), A[i].end());
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
        sort(B[i].begin(), B[i].end());
    }
    sort(A, A+n);
    sort(B, B+n);
    
    int ans=(A[0]==B[0])?1:0,curr=1;
    for(int i=1;i<n;i++){
        if(A[i]!=B[i]) ans=0;
        else{
            if(A[i]==A[i-1]){
                curr++;
            }
            else{
                ans *= curr;
                curr=1;
            }
        }
    }
    ans *= fact(curr);
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