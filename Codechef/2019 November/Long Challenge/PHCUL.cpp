#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 10000000000000.0
using namespace std;

ld dis(pair<ld,ld> a, pair<ld,ld> b){
    return sqrt( ((b.first-a.first)*(b.first-a.first)) + ((b.second-a.second)*(b.second-a.second)) );
}

void solve(){
    int n,m,k;
    ld x,y,a,b;
    cin>>x>>y;
    cin>>n>>m>>k;
    vector<pair<ld, ld>> Apoints, Bpoints, Cpoints;
    vector<ld> AC(n,INF), BC(m,INF);

    for(int i=0;i<n;i++){
        cin>>a>>b;
        Apoints.push_back({a,b});
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        Bpoints.push_back({a,b});
    }
    for(int i=0;i<k;i++){
        cin>>a>>b;
        Cpoints.push_back({a,b});
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            ld d = dis(Bpoints[i], Cpoints[j]);
            BC[i] = min(BC[i], d);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            ld d = dis(Apoints[i], Cpoints[j]);
            AC[i] = min(AC[i], d);
        }
    }

    ld ans=INF;
    pair<ld,ld> o = make_pair(x,y);
    for(int i=0;i<n;i++){
        ld d = dis(o, Apoints[i]);
        for(int j=0;j<m;j++){
            ans = min(ans, d+dis(Apoints[i], Bpoints[j])+BC[j]);
        }
    }
    for(int i=0;i<m;i++){
        ld d = dis(o, Bpoints[i]);
        for(int j=0;j<n;j++){
            ans = min(ans, d+dis(Apoints[j], Bpoints[i])+AC[j]);
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(12)<<fixed;
    int t;
    cin>>t;
    while(t--){ 
        solve();
    }
}