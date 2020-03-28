#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

string temp;

int main(){
    cin>>temp;
    ll len = temp.length();
    vector<ll> arr;
    ll curr=0;
    for(int i=0;i<len;i++){
        if(temp[i]=='a'){
            curr++;
        }
        if(temp[i]=='b' && curr>0){
            arr.push_back(curr);
            curr=0;
        }
    }
    if(curr>0) arr.push_back(curr);
    len = arr.size();
    //cout<<len<<endl;
    ll ans=0;
    for(int i=0;i<len;i++){
        ans = (ans + ( (arr[i]*ans)%MOD + arr[i] )%MOD )%MOD;
    }
    cout<<ans<<endl;
}
