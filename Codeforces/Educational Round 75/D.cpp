#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

bool check(pair<int,int> arr[], int mid, int n, int s){
    vector<pair<int,int>> both;
    int l=0,r=0;
    for(int i=0; i<n;i++){
        if(arr[i].second < mid){
            s -= arr[i].first;
            l++;
        }
        else if(arr[i].first > mid){
            s -= arr[i].first;
            r++;
        }
        else{
            both.push_back(arr[i]);
        }
    }
    if(l>(n/2) || r>(n/2)) return false;
    for(int i=0;i<both.size();i++){
        if(l<(n/2)){
            s -= both[i].first;
            l++;
        }
        else{
            s -= mid;
            r++;
        }
    }
    if(s<0) return false;
    return true;
}

void solve(){
    int n,s,l,r=0,a,b;
    cin>>n>>s;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        cin>>a>>b;
        arr[i] = {a,b};
        r = max(r, b);
    }
    sort(arr, arr+n);
    l = arr[n/2].first;
    r = arr[n].second;
    while(l<r){
        int mid = (l+r+1)/2;
        if(check(arr, mid, n, s)){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }
    cout<<l<<"\n";
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