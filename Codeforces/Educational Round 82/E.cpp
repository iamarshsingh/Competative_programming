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
    string a,b,c="";
    cin>>a>>b;
    int i=((int)a.length())-1,j=((int)b.length())-1;
    while(i>=0 && j>=0){
        if(a[i]==b[j]){
            j--;
            a[i]='0';
        }
        i--;
    }
    for(int k=0;k<a.length();k++){
        if(a[k]!='0') c += string(1,a[k]);
    }
    i=((int)c.length())-1;
    //cout<<c<<" "<<i<<" "<<j<<"\n";
    while(i>=0 && j>=0){
        if(c[i]==b[j]){
            j--;
            c[i]='0';
        }
        i--;
    }
    if(j<0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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