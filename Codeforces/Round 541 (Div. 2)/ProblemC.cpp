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
    deque<int> d;
    for(int i=0;i<n;i++){
        if(i%2==0){
            d.push_back(arr[i]);
        }
        else{
            d.push_front(arr[i]);
        }
    }
    for(int i=0;i<n;i++)cout<<d[i]<<" ";
    cout<<endl;
}
