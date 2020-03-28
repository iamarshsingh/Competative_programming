#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,a,b,temp,maxx=0;
    cin>>n;
    vector<pair<int,int>> arr;
    arr.push_back(make_pair(0,0));
    for(int i=0;i<n;i++){
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }
    ll ans = 1;
    for(int i=1;i<=n;i++){
        if(arr[i].first==arr[i-1].first && arr[i].second==arr[i-1].second){
            continue;
        }
        else{
            temp = min(arr[i].first,arr[i].second) - max(arr[i-1].first,arr[i-1].second);
            if(temp>=0){
                if(max(arr[i-1].first,arr[i-1].second)>maxx){
                    ans += temp+1;
                }
                else{
                    ans += temp;
                }
                //cout<<"here:  "<<temp<<" "<<maxx<<endl;
            }
            maxx = min(arr[i].first,arr[i].second);
        }
    }
    cout<<ans<<endl;
}
