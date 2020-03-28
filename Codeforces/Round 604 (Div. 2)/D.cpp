#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

void solve(){
    int arr[4];
    for(int i=0;i<4;i++) cin>>arr[i];
    int n = arr[0]+arr[1]+arr[2]+arr[3];
    deque<int> ans;
    while(arr[0]>0){
        if(ans.size()>0 && ans[ans.size()-1]==0){
            cout<<"NO\n";
            return;
        }
        if(arr[1]>0){
            ans.push_back(0);
            ans.push_back(1);
            arr[0]--;
            arr[1]--;
        }
        else{
            ans.push_back(0);
            arr[0]--;
        }
    }
    if(arr[1]>0 && arr[2] < (arr[1]+arr[3])){
        arr[1]--;
        ans.push_front(1);
    }
    //cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<"\n";
    while(arr[1]>0){
        if(ans.size()>0 && ans[ans.size()-1]==2){
            cout<<"NO\n";
            return;
        }
        if(arr[2]>0){
            ans.push_back(2);
            ans.push_back(1);
            arr[2]--;
            arr[1]--;
        }
        else{
            if(ans.size()>0 && ans[ans.size()-1]==1){
                cout<<"NO\n";
                return;
            }
            ans.push_back(1);
            arr[1]--;
        }
    }
    //cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<"\n";
    while(arr[2]>0){
        if(ans.size()>0 && (ans[ans.size()-1]==0 || ans[ans.size()-1]==2)){
            cout<<"NO\n";
            return;
        }
        if(arr[3]>0){
            ans.push_back(2);
            ans.push_back(3);
            arr[2]--;
            arr[3]--;
        }
        else{
            ans.push_back(2);
            arr[2]--;
        }
    }
    //cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<"\n";
    if(arr[3]>0 && (ans.size()==0 || ( ans[0]==2 ) ) ) {
        ans.push_front(3);
        arr[3]--;
    }
    if(arr[3]>0 && (ans.size()==0 || ( ans[ans.size()-1]==2 ) ) ) {
        ans.push_back(3);
        arr[3]--;
    }

    if(arr[3]>0 || arr[0]>0 || arr[1]>0 || arr[2]>0){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}