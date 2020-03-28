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

int n,k;

inline string find(string a, string b){
    string ans="";
    for(int i=0;i<k;i++){
        if(a[i]==b[i]) ans += a[i];
        else{
            if( (a[i]=='S' && b[i]=='E' ) || (a[i]=='E' && b[i]=='S') )
                ans += 'T';
            else if( (a[i]=='S' && b[i]=='T' ) || (a[i]=='T' && b[i]=='S') )
                ans += 'E';
            else
                ans += 'S';
        }
    }
    return ans;
}

void solve(){
    cin>>n>>k;
    unordered_map<string, int> s;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s[arr[i]]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        s[arr[i]]--;
        for(int j=i+1;j<n;j++){
            s[arr[j]]--;
            string l = find(arr[i], arr[j]);
            ans += s[l];
            s[arr[j]]++;
        }
        s[arr[i]]++;
    }
    cout<<(ans/3)<<"\n";
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}