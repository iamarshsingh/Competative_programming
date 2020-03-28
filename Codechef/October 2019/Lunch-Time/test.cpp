#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

int merge(int arr[], int temp[], int l, int mid, int r){
    int i=l, j=mid+1, k=l, ans = 0;
    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else if(arr[i]>arr[j]){
            ans += (mid-i+1);
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=r){
        temp[k++] = arr[j++];
    }
    for(i=l; i<=r;i++){
        arr[i] = temp[i];
    }
    return ans;
}

int count(int arr[], int temp[], int l, int r){
    if(l==r){
        temp[l] = arr[l];
        return 0LL;
    }
    int mid = (l+r)/2;
    int c1 = count(arr, temp, l, mid);
    int c2 = count(arr, temp, mid+1, r);
    return (c1 + c2 + merge(arr, temp, l, mid, r));
}

void solve(){
    int n,q,a;
    cin>>n>>q;
    int arr[n]; int temp[n]; int temp2[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int diff[32];
    for(int i=0;i<n;i++){
        temp2[i] = arr[i];
    }
    int ori = count(temp2, temp, 0, n-1);

    for(int i=0;i<=31;i++){
        for(int j=0;j<n;j++){
            temp2[j] = arr[j];
        }
        for(int j=0;j<n;j++){
            temp2[j] = temp2[j] ^ (1LL<<i);
        }
        diff[i] = ori - count(temp2, temp, 0, n-1);
        //cout<<i<<" "<<ori<<" "<<diff[i]<<"\n";
    }
    int tdif;
    string ans="";
    while(q--){
        cin>>a;
        tdif = 0;
        for(int i=0;i<=31;i++){
            if(a%2==1) tdif += diff[i];
            a/=2;
        }
        ans += to_string(ori-tdif);
        ans += "\n";
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