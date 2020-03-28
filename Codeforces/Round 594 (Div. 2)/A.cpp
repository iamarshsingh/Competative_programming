#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

void solve(){
    int n,m,a,o1=0,e1=0,o2=0,e2=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a%2==0) e1++;
        else o1++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a;
        if(a%2==0) e2++;
        else o2++;
    }
    cout<<((e1*e2) + (o1*o2))<<"\n";
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