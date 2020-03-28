#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

int tree[N];
int lazy[N];

void build(int n){
    for(int i=0;i<3*n;i++) tree[i] = 0;
}

void update(int node, int ql, int qr, int l, int r, int v){
    if(l>r){
        return;
    }
    if(ql==l && qr==r){
        tree[node] += v;
    }
    else{
        int qmid = (ql+qr)/2;
        update(2*node, ql, qmid, l, min(r,qmid), v);
        update(2*node+1, qmid+1, qr, max(l,qmid+1), r, v);
    }
}

int get(int node, int ql, int qr, int l, int r){
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}

void solve(){
    int n,c;
    cin>>n>>c;
    build(n);
    int t,l,r;
    cin>>t>>l>>r;
    if(t==0){
        int v; cin>>v;

    }
    else{

    }
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