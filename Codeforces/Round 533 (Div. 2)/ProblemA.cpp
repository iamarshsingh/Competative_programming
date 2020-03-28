#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int cost=0,ans=0,mincost=INT_MAX;
    for(int t=1;t<=100;t++){
        cost=0;
        for(int i=0;i<n;i++){
            if(arr[i]<t-1){
                cost = cost + abs(t-1-arr[i]);
            }
            else if(arr[i]>t+1){
                cost = cost + abs(arr[i]-t-1);
            }
        }
        if(cost<mincost){
            mincost = cost;
            ans = t;
        }
    }
    cout<<ans<<" "<<mincost<<endl;
}
