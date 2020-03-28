#include <iostream>
#include <vector>
using namespace std;

#define int long long int

void solve(int n){
    if(n==0 || n==1){
        cout<<0<<"\n";
        return;
    }
    if(n==2){
        cout<<3<<"\n";
        return;
    }
    vector<int> d(n+1,0), a(n+1,0);
    a[0] = 0; a[1] = 1; a[2] = 0;
    d[0] = 0; d[1] = 0; d[2] = 3;
    for(int i=3;i<=n;i++){
        a[i] = d[i-1]+a[i-2];
        d[i] = d[i-2]+2*a[i-1];
    }
    cout<<d[n]<<"\n";
}

signed main(){
    int n;
    cin>>n;
    while(n!=-1){
        solve(n);
        cin>>n;
    }
}