#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

int n, t[N];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int minn(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INF;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(minn(v*2, tl, tm, l, min(r, tm)), minn(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve(){
    int k1,k2,k3,tot,num;
    cin>>k1>>k2>>k3;
    tot = k1+k2+k3;
    n=tot;
    set<int> a,b,c;
    for(int i=0;i<k1;i++){
        cin>>num;
        a.insert(num);
    }
    for(int i=0;i<k2;i++){
        cin>>num;
        b.insert(num);
    }
    for(int i=0;i<k3;i++){
        cin>>num;
        c.insert(num);
    }
    vector<int> asum(n+1,0), bsum(n+1,0), csum(n+2,0);
    for(int i=1;i<=n;i++){
        if(a.find(i)!=a.end()){
            asum[i] = asum[i-1];
        }
        else{
            asum[i] = asum[i-1]+1;
        }
        if(b.find(i)!=b.end()){
            bsum[i] = bsum[i-1];
        }
        else{
            bsum[i] = bsum[i-1]+1;
        }
    }
    for(int i=n;i>0;i--){
        if(c.find(i)!=c.end()){
            csum[i] = csum[i+1];
        }
        else{
            csum[i] = csum[i+1]+1;
        }
    }
    int arr[n+1];
    for(int i=1;i<=n+1;i++){
        arr[i-1] = csum[i] + bsum[i-1];
    }
    
    int minn=arr[n],ans=tot;
    for(int i=n;i>=0;i--){
        minn=min(minn, arr[i]);
        //cout<<i<<" : "<<asum[i]<<" "<<bsum[i]<<" "<<arr[i]<<" "<<minn<<"\n";
        ans = min(ans, asum[i]-bsum[i]+minn);
    }
    cout<<ans<<"\n";
    // build(arr, 1, 0, n-1);
    // int ans=tot;
    // for(int i=0;i<=tot;i++){
    //     cout<<i<<" : "<<asum[i]<<" "<<bsum[i]<<" "<<minn(1, 0, n-1, i, n-1)<<"\n";
    //     ans = min(ans, asum[i]-bsum[i]+minn(1, 0, n-1, i, tot));
    // }
    // cout<<ans<<"\n";
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}