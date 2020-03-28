#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool comp(pair<pair<int,int>, pair<int,int>> a, pair<pair<int,int>, pair<int,int>> b){
    if(a.first.first == b.first.first){
        if(a.second.second == b.second.second){
            return a.second.first > b.second.first;
        }
        return a.second.second > b.second.second;
    }
    return a.first.first < b.first.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;
    pair<pair<int,int>, pair<int,int>> arr[k];
    for(int i=0;i<k;i++){
        cin>>arr[i].first.first;
        cin>>arr[i].first.second;
        cin>>arr[i].second.first;
        cin>>arr[i].second.second;
    }
    sort(arr, arr+k, comp);
    //cout<<"here"<<endl;
    vector<ll> ans;
    int pos=0, time = 0;
    while(time<=n && pos<k){
        if(arr[pos].first.second>=time){
            ans.push_back(arr[pos].second.second);
            time = arr[pos].second.first+1;
            pos++;
        }
        else{
            pos++;
        }
    }
    sort(ans.begin(),ans.end());
    int len = ans.size();
    ll res=0;
    for(int i=0;i<len-m;i++){
        cout<<ans[i]<<endl;
        res += ans[i];
    }
    cout<<res<<endl;
}
