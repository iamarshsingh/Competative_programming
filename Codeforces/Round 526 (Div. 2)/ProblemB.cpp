#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,s, minE = 100000000000000;
    ll ans=0, sum=0;
    cin>>n>>s;
    ll arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum = sum+arr[i];
        minE = (arr[i]<minE)?arr[i]:minE;
    }

    if(sum<s){
        cout<<-1<<endl;
    }
    else if(sum==s){
        cout<<0<<endl;
    }
    else{
        sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + arr[i] - minE;
        }
        if(sum>=s){
            cout<<minE<<endl;
        }
        else{
            cout<<(minE - ((s-sum-1)/n) - 1)<<endl;
        }
    }

}
