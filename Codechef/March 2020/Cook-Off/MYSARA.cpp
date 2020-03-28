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

int power(int a, int b, int m=MOD){
    int ans = 1;
    while (b > 0) 
    {
        if (b & 1) 
            ans = (ans*a)%m; 
        
        b = b>>1;
        a = (a*a)%m;
    }
    return ans;
}

int inv(int a, int m=MOD){
    return power(a,m-2,m);
}

void solve(){
    int n;
    cin>>n;
    int ans = 1;
    int s,prev=0;
    for(int i=0;i<n;i++){
        cin>>s;
        if((prev&s)!=prev) ans=0;
        prev=s;
        if(i==(n-1)) continue;
        int l=0;
        while(s>0){
            if(s%2==1){
                //cout<<"s: "<<s<<"\n";
                l++;
            }
            s/=2;
        }
        //cout<<"l: "<<l<<"\n";
        ans = (ans * power(2,l))%MOD;
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