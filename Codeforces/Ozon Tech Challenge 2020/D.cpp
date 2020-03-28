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

vector<vector<int>> arr;

signed main(){
    int n,a,b;
    cin>>n;
    arr.resize(n+1);
    for(int i=0;i<n;i++) arr[i].clear();
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    if(n==2){
        cout<<"? 1 2"<<endl;
        cin>>a;
        cout<<"! "<<a<<endl;
        return 0;
    }
    //cout<<arr<<endl;
    int node = 1, par = 1, finpar = 1;
    vector<bool> vis(n+1,false);
    while(true){
        finpar = par;
        a=-1; b=-1;
        par = node;
        for(int i=0;i<arr[node].size(); i++){
            //cout<<i<<" ";
            //cout<<arr[node][i]<<"\n";
            if(vis[arr[node][i]]) continue;
            if(a==-1){
               a=arr[node][i];
            }
            else if(b==-1){
                b=arr[node][i];
                vis[a] = true;
                vis[b] = true;
                cout<<"? "<<a<<" "<<b<<endl;
                cout.flush();
                cin>>node;
                finpar = node;
                if(node!=par) break;
                a = -1; b = -1;
            }
        }
        if(a!=-1 && b==-1){
            node = a;
            //cout<<node<<"\n";
            continue;
        }
        if(node==par) break;
    }
    cout<<"! "<<(finpar)<<endl;
    cout.flush();
}