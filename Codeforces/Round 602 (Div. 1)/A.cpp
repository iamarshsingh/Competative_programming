#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<pair<int,int>> ans;
    string des="";
    for(int i=1;i<k;i++){
        des += "()";
    }
    int maxx=(n/2);
    for(int i=0;i<(maxx-k+1);i++){
        des += "(";
    }
    for(int i=0;i<(maxx-k+1);i++){
        des += ")";
    }
    for(int i=0;i<n;i++){
        if(s[i]!=des[i]){
            int j=i+1;
            while(s[j]!=des[i]) j++;
            string temp = s.substr(i, (j-i+1));
            reverse(temp.begin(), temp.end());
            for(int k=i;k<=j;k++){
                s[k] = temp[k-i];
            }
            ans.push_back({i+1, j+1});
        }
    }
    //cout<<des<<"\n";
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}

signed main(){
    //fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}