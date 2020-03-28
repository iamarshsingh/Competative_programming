#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int n,m,a;
    cin>>n>>m;
    int x,y,s;
    cin>>x>>y>>s;
    vector<int> rows, cols;
    rows.push_back(0);
    cols.push_back(0);
    for(int i=0;i<x;i++){
        cin>>a;
        rows.push_back(a);
    }
    for(int i=0;i<y;i++){
        cin>>a;
        cols.push_back(a);
    }
    rows.push_back(n+1);
    cols.push_back(m+1);
    int sum1=0, sum2=0;
    for(int i=1;i<rows.size();i++){
        //cout<<((rows[i]-rows[i-1]-1)/s)<<" ";
        sum1 += ((rows[i]-rows[i-1]-1)/s);
    }
    //cout<<"\n";
    for(int i=1;i<cols.size();i++){
        //cout<<((cols[i]-cols[i-1]-1)/s)<<" ";
        sum2 += ((cols[i]-cols[i-1]-1)/s);
    }
    //cout<<"\n";
    //cout<<sum1<<" "<<sum2<<"\n";
    cout<<(sum1*sum2)<<"\n";
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