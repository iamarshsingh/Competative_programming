#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    int arr[n],le=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<=x)le++;
    }
    if(x>y){
        cout<<n<<endl;
        return 0;
    }
    sort(arr,arr+n);
    int i=0,j=le-1;
    for(;i<=j;i++){
        arr[i] = 0;
        arr[j] = arr[j] + y;
        if(arr[j]>x){
            j--;
        }
    }
    cout<<i<<endl;
}
