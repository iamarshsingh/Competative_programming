#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    ll sum=0;
    for(int i=0;i<(n/2);i++){
        sum += ((arr[i]+arr[n-i-1])*(arr[i]+arr[n-i-1]));
    }
    cout<<sum<<endl;
}
