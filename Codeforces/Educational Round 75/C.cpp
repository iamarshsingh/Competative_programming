#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    deque<int> arr;
    arr.push_back(s[0] - '0');
    vector<int> ans;
    int prevp = (arr[0])%2;

    for(int i=1;i<n;i++){
        int currp = ((s[i] - '0')%2);
        if(currp == prevp){
            arr.push_back((s[i] - '0'));
        }
        else{
            while(!arr.empty() && arr.front() < (s[i]-'0')){
                ans.push_back(arr.front());
                arr.pop_front();
            }
            if(arr.empty()){
                prevp = currp;
                arr.push_back((s[i]-'0'));
            }
            else{
                ans.push_back((s[i]-'0'));
            }
        }
    }
    while(!arr.empty()){
        ans.push_back(arr.front());
        arr.pop_front();
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
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