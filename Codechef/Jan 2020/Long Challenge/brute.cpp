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

int n,sum,ans=0;

void check(multiset<int> arr, int curr){
    if(arr.size()<=n){
        if(curr==sum) ans++;
        return;
    }
    for(int i:arr){
        cout<<i<<"\n";
        arr.erase(i);
        check(arr, curr+i);
        arr.insert(i);
    }
}

void solve(){
    int a;
    sum=0;
    cin>>n;
    multiset<int> arr;
    // unordered_map<int,int> freq;
    // set<int> un;
    for(int i=0;i<2*n;i++){
        cin>>a;
        arr.insert(a);
        sum += a;
    }
    sum = sum/(n+1);
    check(arr,0);
    cout<<ans<<"\n";
}

signed main(){
    // fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}