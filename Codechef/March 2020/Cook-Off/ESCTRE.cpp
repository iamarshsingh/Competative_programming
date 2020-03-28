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
    int h;
    cin>>h;
    int dis, curr=2;
    cout<<"1 2"<<endl;
    cin>>dis;
    if(dis==0) h=0;
    while(h>0){
        cout<<"2 "<<curr<<" "<<dis<<endl;
        cin>>curr;
        cout<<"1 "<<curr<<endl;
        cin>>dis;
        if(dis==0) break;
        h--;
    }
    cout<<"3 "<<curr<<endl;
    cin>>curr;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}