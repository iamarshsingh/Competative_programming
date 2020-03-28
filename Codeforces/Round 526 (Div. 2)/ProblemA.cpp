#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,temp;
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        ans += (temp*i*4);
    }
    cout<<ans<<endl;
}
