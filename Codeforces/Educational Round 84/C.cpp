#include <bits/stdc++.h>
#define ld long double
#define MOD 1000000007
#define N 1000006
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

#define int long long int

void solve(){
    int a,n,m,k;
    cin>>n>>m>>k;
    string ans = "";

    for(int i=0;i<(4*k);i++){
        cin>>a;
    }
    if(n==1 && m==1){
        cout<<"0\n\n";
        return;
    }
    else if(n==1){
        for(int i=0;i<(m-1);i++){
            ans += "L";
        }
        for(int i=0;i<(m-1);i++){
            ans += "R";
        }
    }
    else if(m==1){
        for(int i=0;i<(n-1);i++){
            ans += "U";
        }
        for(int i=0;i<(n-1);i++){
            ans += "D";
        }
    }
    else{
        for(int i=0;i<(m-1);i++){
            ans += "L";
        }
        for(int i=0;i<(n-1);i++){
            ans += "U";
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                for(int j=0;j<(m-1);j++){
                    ans += "R";
                }
                ans += "D";
            }
            else{
                for(int j=0;j<(m-1);j++){
                    ans += "L";
                }
                ans += "D";
            }
        }
    }
    cout<<ans.length()<<"\n";
    cout<<ans<<"\n";
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}