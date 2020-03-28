#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<(a*10)<<" "<<(b*10 + 1)<<"\n";
    }
    else if(a+1==b){
        cout<<a<<" "<<b<<"\n";
    }
    else if(a==9 && b==1){
        cout<<a<<" "<<(b*10)<<"\n";
    }
    else{
        cout<<-1<<endl;
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