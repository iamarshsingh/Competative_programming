#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll diss(pair<ll,ll> a, pair<ll,ll> b){
    return ( ((a.first-b.first)*(a.first-b.first)) + ((a.second-b.second)*(a.second-b.second)) );
}

int main(){
    ll n,prev;
    cin>>n;
    pair<ll,ll> arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        cin>>arr[i].second;
    }
    vector<ll> dis[n];
    for(int i=0;i<n;i++){
        prev=0;
        dis[i].clear();
        for(int j=i;j<n;j++){
            dis[i].push_back(max(diss(arr[i],arr[j]),prev));
            prev = dis[i][j-i];
        }
        /*
        for(int j=0;j<dis[i].size();j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
        */
    }
    ll q,l,r,maxx;
    cin>>q;
    while(q--){
        maxx=0;
        cin>>l>>r;
        l--;
        r--;
        for(int i=l;i<=r;i++){
            //cout<<i<<" "<<r-i<<"   :   "<<dis[i][r-i]<<endl;
            if(dis[i][r-i]>=maxx){
                maxx=dis[i][r-i];
            }
        }
        cout<<maxx<<endl;
    }
    return 0;
}
