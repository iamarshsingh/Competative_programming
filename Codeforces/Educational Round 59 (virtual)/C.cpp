#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main(){
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    string s;
    cin>>s;
    ll i=0,j=1;
    ll ans=0;
    while(j<n){
        if(s[i]==s[j]){
            j++;
        }
        else{
            if(j-i+1>k){
                sort(arr+i,arr+j);
                for(int k=i;k<(j-k);k++){
                    arr[k]=0;
                }
            }

            i=j;
            j++;
        }
    }
    for(int i=0;i<n;i++){
        ans+=arr[i];
    }
    cout<<ans<<endl;
    return 0;
}
