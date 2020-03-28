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

vector<vector<int>> g;
vector<int> l;
vector<int> ans;
set<int> done;
bool poss = true;

vector<int> post(int node, int &curr){
    vector<int> curvec;
    if(!poss) return curvec;
    for(int i:g[node]){
        vector<int> rec = post(i, curr);
        if(rec.size()>0) curvec.insert(curvec.end(), rec.begin(), rec.end());
    }
    // cout<<node<<" "<<curvec<<" ";
    if(!poss) return curvec;
    sort(all(curvec));
    if(curvec.empty()){
        ans[node] = curr;
        curr += 1000000;
    }
    else{
        if(curvec.size()<l[node]){
            poss=false;
            return curvec;
        }
        int lo = curvec[l[node]-1];
        int hi;
        if(curvec.size()>l[node]){
            hi = curvec[l[node]];
        }
        else{
            hi = 1000000000;
        }
        //cout<<"lh: "<<lo<<" "<<hi<<"\n";
        int mid = (lo+hi)/2;
        while(done.find(mid)!=done.end()){
            hi=mid-1;
            mid = (lo+hi)/2;
        }
        ans[node] = mid;
    }
    done.insert(ans[node]);
    curvec.push_back(ans[node]);
    // cout<<" "<<ans[node]<<"\n";
    return curvec;
}

void solve(){
    int n,a,b;
    cin>>n;
    g.clear();
    l.clear();
    ans.clear();
    g.resize(n);
    l.resize(n);
    ans.resize(n);
    int root;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        l[i] = b;
        if(a>0) g[a-1].push_back(i);
        if(a==0) root=i;    
    }
    int curr=1000000;
    post(root, curr);
    if(poss){
        cout<<"YES\n";
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<"NO\n";
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