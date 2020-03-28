#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9 + 7
#define N 1e6 + 5
#define INF 1e17
using namespace std;

void solve(){
    int n,k,m,x,y,z;
    cin>>n>>k>>m;
    pair<int, pair<int,int>> arr[m];
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        arr[i] = {z-1, {x, y}};
    }
    sort(arr, arr+n);
    int filled=0;
    vector<int> ans(n,0);
    vector<int> freq(n+1,0);
    for(int i=0;i<m;i++){
        cout<<arr[i].first<<" "<<arr[i].second.first<<" "<<arr[i].second.second<<"\n";

        if(ans[arr[i].first]==0 || ans[arr[i].first]==arr[i].second.first){

            ans[arr[i].first] = arr[i].second.first;
            freq[arr[i].second.first]++;
            
            while(freq[arr[i].second.first]<arr[i].second.second && filled < arr[i].first){
                while(ans[filled]!=0) filled++;
                ans[filled] = arr[i].second.second;
                freq[arr[i].second.second]++;
            }

            if(freq[arr[i].second.first] != arr[i].second.second){
                cout<<"1NO"<<"\n";
                return;
            }
            
        }
        else{
            cout<<"2NO"<<"\n";
            return;
        }
    }
    cout<<"YES"<<"\n";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}