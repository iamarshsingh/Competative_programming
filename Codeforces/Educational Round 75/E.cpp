#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

int m[N];
int p[N];

struct comp{
    bool operator ()(const int &a, const int &b) const{
        if(p[a] == p[b]){
            return m[a]>m[b];
        }
        return p[a]<p[b];
    }
};

void solve(){
    int n;
    cin>>n;
    set<int> voters[n+1];
    set<int, comp> s;
    for(int i=0;i<n;i++){
        cin>>m[i]>>p[i];
        voters[m[i]].insert(i);
        s.insert(i);
    }
    int ans=0, curv = 0, prev=0;
    while(!s.empty()){
        while(prev <=n && prev<=curv){
            //cout<<prev<<" "<<curv<<"\n";
            for(int i: voters[prev]){
                s.erase(i);
                voters[prev].erase(i);
                curv++;
            }
            prev++;
        }
        if(!s.empty()){
            int i = *s.begin();
            ans += p[i];
            s.erase(i);
            voters[m[i]].erase(i);
            curv++;
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}