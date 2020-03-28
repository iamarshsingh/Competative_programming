#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

bool comp(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b){
    if(a.second.first==b.second.first){
        return a.second.second<b.second.second;
    }
    else return a.second.first<b.second.first;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        pair<int, pair<int,int>> arr[n];
        for(int i=0;i<n;i++){
            arr[i].first=i;
            cin>>arr[i].second.first>>arr[i].second.second;
        }

        sort(arr,arr+n,comp);
        //for(int i=0;i<n;i++){
        //    cout<<arr[i].second.first<<arr[i].second.second<<endl;
        //}
        bool pos=false;
        int ans[n];
        int curr = arr[0].second.second;
        ans[arr[0].first]=1;
        for(int i=1;i<n;i++){
            if(arr[i].second.first>curr){
                pos=true;
            }
            if(pos){
                ans[arr[i].first]=2;
            }
            else{
                ans[arr[i].first]=1;
                if(arr[i].second.second>curr)curr = arr[i].second.second;
            }
        }
        if(pos){
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        else cout<<-1<<endl;

    }
    return 0;
}
