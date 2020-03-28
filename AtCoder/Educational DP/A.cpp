#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],ans[n];
    for(int i=0;i<n;i++){
        ans[i]=0;
        cin>>arr[i];
    }
    ans[0]=0;
    ans[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++){
        ans[i] = min( ans[i-1] + abs(arr[i]-arr[i-1]) , ans[i-2] + abs(arr[i]-arr[i-2]) );
        //cout<<ans[i]<<" ";
    }
    cout<<ans[n-1]<<endl;
}
