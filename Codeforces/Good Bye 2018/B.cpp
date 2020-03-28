#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;
vector<pair<ll,ll>> ans;

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}

int main(){
    int n;
    cin>>n;
    pair<ll,ll> cor[n];
    pair<ll,ll> vec[n];
    for(int i=0;i<n;i++){
        cin>>cor[i].first>>cor[i].second;
    }
    for(int i=0;i<n;i++){
        cin>>vec[i].first>>vec[i].second;
    }
    if(n==1){
        cout<<cor[0].first+vec[0].first<<" "<<cor[0].second+vec[0].second<<endl;
        return 0;
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
                pair<ll,ll> temp;
                temp.first = cor[i].first+vec[j].first;
                temp.second = cor[i].second+vec[j].second;
                ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end(),comp);
    //for(ll i=0;i<n*n;i++){
    //    cout<<ans[i].first<<" "<<ans[i].second<<endl;
    //}
    for(ll i=n-1;i<n*n;i++){
        if(ans[i].first==ans[i-n+1].first && ans[i].second==ans[i-n+1].second){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
            return 0;
        }
    }
    return 0;
}
