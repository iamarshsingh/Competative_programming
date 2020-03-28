#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

ld sum=0;
ld num=0;
int n;
vector<pair<ld,ld>> coor;

ld dis(int i, int j){
    return sqrt( ((coor[j].first - coor[i].first)*(coor[j].first - coor[i].first)) + ((coor[j].second - coor[i].second)*(coor[j].second - coor[i].second)) );
}

void trav(vector<bool> visited, int curr, int don, ld curdis){
    //cout<<curr<<" "<<don<<"\n";
    if(don==n){
        sum += curdis;
        num++;
        return;
    }
    //cout<<"here"<<"\n";
    visited[curr]=true;
    //cout<<"here"<<"\n";
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i] = true;
            trav(visited, i, don+1, curdis + dis(curr,i) );
            visited[i] = false;
        }
    }
}

void solve(){
    cin>>n;
    coor.resize(n);
    for(int i=0;i<n;i++){
        cin>>coor[i].first>>coor[i].second;
    }
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        trav(visited, i, 1, 0);
    }
    cout<<(sum/num)<<"\n";
}

signed main(){
    cout<<setprecision(10)<<fixed;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}