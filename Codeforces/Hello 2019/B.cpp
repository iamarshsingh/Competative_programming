#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll poww(ll a, ll b){
    ll ans = a;
    for(int i=1;i<b;i++){
        ans = ans*a;
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll up = poww(2,n);
    for(ll k=0;k<up;k++){
        int temp=0;
        ll i=k;
        for(int j=0;j<n;j++){
            if(i%2==0){
                temp = temp + arr[j];
            }
            else{
                temp = temp - arr[j];
            }
            i=i/2;
        }
        //cout<<temp;
        if(temp%360==0){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
