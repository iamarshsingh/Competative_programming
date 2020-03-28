#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    return a.first<b.first;
}

int main(){
    ll n,m;
    cin>>n>>m;
    pair<ll,ll> arr1[n], arr2[m];
    for(ll i=0;i<n;i++){
        cin>>arr1[i].first;
        arr1[i].second=i;
    }
    for(ll i=0;i<m;i++){
        cin>>arr2[i].first;
        arr2[i].second=i;
    }
    sort(arr1,arr1+n,comp);
    sort(arr2,arr2+m,comp);
    for(ll i=0;i<m;i++)cout<<arr1[0].second<<" "<<arr2[i].second<<endl;
    for(ll i=1;i<n;i++)cout<<arr1[i].second<<" "<<arr2[m-1].second<<endl;
    return 0;
}
