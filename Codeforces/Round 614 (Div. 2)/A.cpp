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

void solve(){
    int n,s,k,a;
    cin>>n>>s>>k;
    set<int> ss;
    for(int i=0;i<k;i++){
        cin>>a;
        ss.insert(a);
    }
    if(ss.find(s)==ss.end()) {
        cout<<"0\n";
        return;
    }
    for(int i=1;i<=1000;i++){
        if(s+i<=n && ss.find(s+i)==ss.end()){
            cout<<i<<"\n";
            return;
        }
        else if(s-i>0 && ss.find(s-i)==ss.end()){
            cout<<i<<"\n";
            return;
        }
    }
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}