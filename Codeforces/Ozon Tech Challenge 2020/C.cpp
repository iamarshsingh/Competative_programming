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

//#define int long long int

template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.F<<','<< P.S<<')';}

signed main(){
    fastio
    int n,m,a;
    cin>>n>>m;
    int ans=1;
    int freq[m]={0};
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(freq[j]==0) continue;
            //cout<<arr[i]<<" "<<j<<" "<<freq[j]<<"\n";
            ans *= (freq[j] * ((arr[i]-j+m)%m) );
            ans %= m;
        }
        if(ans==0) break;
        freq[(arr[i]%m)]++;
    }
    cout<<ans<<"\n";
}