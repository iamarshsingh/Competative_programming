#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    long long ans=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    for(int i=1;i<n;i=i+2){
        ans += (arr[i]-arr[i-1]);
    }
    cout<<ans<<endl;
}
