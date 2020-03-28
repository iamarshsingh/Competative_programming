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
    int n,m;
    cin>>n>>m;
    int arr[m];
    int sum=0;
    for(int i=0;i<m;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr, arr+m);
    if(n>sum){
        cout<<"-1\n";
        return;
    }
    int ans=0,left=sum-n;

    for(int i=m-1;i>=0;i--){
        while(arr[i]>1 && left>0 && left>=(arr[i]/2)){
            arr[i] = arr[i]/2;
            left = left - (arr[i]);
            ans++;
        }
        if(left==0) break;
    }
    cout<<ans<<"\n";
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}