#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

int ans;

void merge(vector<int> &arr, vector<int> &temp, int l, int r, int mid){
    int i = l;
    int j = mid;
    int k = l;
    while(i<mid && j<=r){
        //cout<<i<<" "<<j<<" "<<arr[i]<<" "<<arr[j]<<"\n";
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            ans += (mid-i);
        }
    }
    while(i<mid){
        temp[k++] = arr[i++];
    }
    while(j<=r){
        temp[k++] = arr[j++];
    }
    for(i=l;i<=r;i++) arr[i] = temp[i];
    //cout<<l<<" "<<r<<" mid: "<<mid<<"  ans: "<<ans<<"\n";
}

void mergeAndCount(vector<int> &arr, vector<int> &temp, int l, int r){
    if(l<=r){
        int  mid = (l+r)/2;
        //cout<<l<<" "<<r<<" "<<ans<<"\n";
        if(l<r){
            mergeAndCount(arr, temp, l, mid);
            mergeAndCount(arr, temp, mid+1, r);
            merge(arr, temp, l, r, mid+1);
        }
        else{
            temp[l] = arr[l];
        }
    }
}

void cal(vector<int> &arr){
    vector<int> temp(arr.size());
    mergeAndCount(arr, temp, 0, arr.size()-1);
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ans=0;
    cal(arr);
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