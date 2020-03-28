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
    int n,q,a,b;
    cin>>n>>q;
    int arr[2][n];
    for(int i=0;i<n;i++) arr[0][i] = arr[1][i] = 0;
    set<pair<int,int>> block;
    while(q--){
        cin>>a>>b;
        a--; b--;
        arr[a][b] = (arr[a][b]==0)?1:0;
        if(arr[a][b]==1){
            int aa = (a==0)?1:0;
            if(b-1>=0 && arr[aa][b-1]==1){
                if(a==0)
                    block.insert({b,b-1});
                else
                    block.insert({b-1,b});
            }
            if(arr[aa][b]==1){
                if(a==0)
                    block.insert({b,b});
                else
                    block.insert({b,b});
            }
            if(b+1<n && arr[aa][b+1]==1){
                if(a==0)
                    block.insert({b,b+1});
                else
                    block.insert({b+1,b});
            }
        }
        else{
            if(a==0){
                if(b-1>=0 && block.find({b,b-1})!=block.end()) block.erase({b,b-1});
                if(block.find({b,b})  !=block.end()) block.erase({b,b});
                if(b+1<n && block.find({b,b+1})!=block.end()) block.erase({b,b+1}); 
            }
            else{
                if(b-1>=0 && block.find({b-1,b})!=block.end()) block.erase({b-1,b});
                if(block.find({b,b})  !=block.end()) block.erase({b,b});
                if(b+1<n && block.find({b+1,b})!=block.end()) block.erase({b+1,b});
            }
        }
        if(block.size()>0) cout<<"No\n";
        else cout<<"Yes\n";
    }
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}