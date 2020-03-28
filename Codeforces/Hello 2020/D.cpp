#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

using pii = pair<int,int>;

bool comp1(pair<pii,pii> a, pair<pii,pii> b){
    return a.F.S < b.F.S;
}

bool comp(pair<pii,pii> a, pair<pii,pii> b){
    return a.S.S < b.S.S;
}

void solve(){
    int n;
    cin>>n;
    multiset<int> l;
    multiset<int> r;
    int a,b,c,d;
    vector<pair<pii,pii>> v(n);
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        v[i] = {{a,b}, {c,d}};
    }
    sort(v.begin(), v.end(), comp1);
    l.clear();
    r.clear();
    int i=0,j=0;
    while(j<n){
        while(i<j && v[i].F.S < v[j].F.F){
            l.erase(v[i].S.F);
            r.erase(v[i].S.S);
            i++;
        }
        l.insert(v[j].S.F);
        r.insert(v[j].S.S);
        //cout<<i<<" "<<j<<" ";
        //cout<<findMax(l)<<" "<<findMin(r)<<"\n";
        if((*l.rbegin()) > (*r.begin())){
            cout<<"NO\n";
            return;
        }
        j++;
    }

    sort(v.begin(), v.end(), comp);
    l.clear();
    r.clear();
    i=0;j=0;
    while(j<n){
        while(i<j && v[i].S.S < v[j].S.F){
            l.erase(v[i].F.F);
            r.erase(v[i].F.S);
            i++;
        }
        l.insert(v[j].F.F);
        r.insert(v[j].F.S);
        //cout<<i<<" "<<j<<" ";
        //cout<<findMax(l)<<" "<<findMin(r)<<"\n";
        if((*l.rbegin()) > (*r.begin())){
            cout<<"NO\n";
            return;
        }
        j++;
    }
    cout<<"YES\n";
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}