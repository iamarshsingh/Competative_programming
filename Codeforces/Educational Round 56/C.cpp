#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;
    ll arr[n/2];
    ll ans[n];
    for(ll i=0;i<n/2;i++)cin>>arr[i];

    if(arr[n/2 - 1]%2==0){
        ans[n/2 - 1] = ans[n/2] = arr[n/2 - 1]/2;
    }
    else{
        ans[n/2 - 1] = ans[n/2] = arr[n/2 - 1]/2;
        ans[n/2]++;
    }


    for(ll i=(n/2 - 2);i>=0;i--){
        ll temp = (arr[i+1] - arr[i]);
        if(temp>0){
            ans[i] = ans[i+1] - (temp);
            ans[n-i-1] = ans[n-i-2] ;
        }
        else{
            ans[i] = ans[i+1];
            ans[n-i-1] = ans[n-i-2] - temp;
        }
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
