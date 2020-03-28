#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    ll n,k;
    cin>>n>>k;
    vector<int> pos;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(i<k){
                int temp = (i) + ((n/i)*k);
                //cout<<(((int)(temp/k))+(temp%k) )<<endl;
                if((((int)(temp/k))*(temp%k) )== n)pos.push_back(temp);
            }
            if((n/i)<k){
                int temp = (i*k) + ((n/i));
                if((((int)(temp/k))*(temp%k) )== n)pos.push_back(temp);
            }
        }
    }
    int mini=INT_MAX;
    for(int i=0;i<pos.size();i++){
        if(pos[i]<mini)mini=pos[i];
    }
    //cout<<pos.size()<<endl;
    cout<<mini<<endl;
}
