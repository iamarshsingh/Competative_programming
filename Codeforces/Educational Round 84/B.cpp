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
{return cout<<'('<<P.F<<','<< P.S<<')';}

void solve(){
    int n;
    cin>>n;
    set<int> boys;
    set<int> girls;
    for(int i=1;i<=n;i++){
        boys.insert(i);
        girls.insert(i);
    }

    int k,a;
    for(int i=1;i<=n;i++){
        cin>>k;
        bool done = false;
        for(int j=0;j<k;j++){
            cin>>a;
            if(done) continue;
            if(boys.find(a)!=boys.end()){
                done = true;
                boys.erase(a);
            }
        }
        if(done){
            girls.erase(i);
        }
    }
    if(!girls.empty() && !boys.empty()){
        cout<<"IMPROVE\n";
        cout<<*girls.begin()<<" "<<*boys.begin()<<"\n";
    }
    else{
        cout<<"OPTIMAL\n";
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