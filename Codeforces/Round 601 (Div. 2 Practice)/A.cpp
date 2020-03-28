#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

char cs[63];

void solve(){
    int r,c,k,rice=0;
    cin>>r>>c>>k;
    string s[r];
    for(int i=0;i<r;i++){
        cin>>s[i];
        for(int j=0;j<c;j++){
            if(s[i][j]=='R') rice++;
        }
    }

    vector<string> ans(r,s[0]);
    vector<int> freq(k,(rice/k));
    rice = rice%k;
    for(int i=0;i<rice;i++){
        freq[i]++;
    }
    int pos=0,curr=0,i=0,j=0;
    while(i<r){
        if(s[i][j]=='R'){
            if(freq[pos]==0) pos++;
            freq[pos]--;
        }
        ans[i][j] = cs[pos];
        if(i%2==0) j++;
        else j--;
        if(j==c){
            j--;
            i++;
        }
        else if(j==-1){
            j++;
            i++;
        }
    }
    for(int i=0;i<r;i++){
        cout<<ans[i]<<"\n";
    }
}

signed main(){
    
    for(int i=0;i<26;i++){
        cs[i] = 'a'+i;
    }
    for(int i=0;i<26;i++){
        cs[i+26] = 'A'+i;
    }
    for(int i=0;i<10;i++){
        cs[i+52] = '0'+i;
    }

    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}