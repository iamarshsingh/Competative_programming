#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 100005
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

int n, t[4*N];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void solve(){
    int a;
    cin>>n;
    int arr[N]={0};
    build(arr, 1, 0, N-1);
    for(int i=0;i<n;i++){
        cin>>a;
        arr[a]++;
        //cout<<a<<endl;
        update(1, 0, N-1, a-1, sum(1, 0, N-1, a-1, a-1)+1);
        int l=0, r=i;
        while(l<r){
            int mid=(l+r+1)/2;
            if(sum(1, 0, N-1, mid, N-1)>=(mid+1)){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        cout<<(l+1)<<" ";
    }
}

signed main(){
    fastio
    int t;
    cin>>t;
    for(int c=1;c<=t;c++){
        cout<<"Case #"<<c<<": ";
        solve();
        cout<<"\n";
    }
}