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
    int n,g,b;
    cin>>n>>g>>b;
    if(g>=b) cout<<n<<"\n";
    else{
        int good = ceil(n/2.0);
        int times = ceil(good/((double)g));
        //cout<<good<<" "<<times<<" ";
        int ans = n - ((g*(times-1)) + min((b*(times-1)),n-good));
        //cout<<ans<<" ";
        ans = ans + ((g+b)*(times-1));
        cout<<ans<<"\n";
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

// 11 3 4