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

template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.x<<','<< P.y<<')';}

void solve(int n){
    if(n==0 || n==1){
        cout<<0<<"\n";
        return;
    }
    if(n==2){
        cout<<3<<"\n";
        return;
    }
    vector<int> d(n+1,0), a(n+1,0);
    a[0] = 0; a[1] = 1; a[2] = 0;
    d[0] = 0; d[1] = 0; d[2] = 3;
    for(int i=3;i<=n;i++){
        a[i] = d[i-1]+a[i-2];
        d[i] = d[i-2]+2*a[i-1];
    }
    cout<<d[n]<<"\n";
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    int n;
    cin>>n;
    while(n!=-1){
        solve(n);
        cin>>n;
    }
}