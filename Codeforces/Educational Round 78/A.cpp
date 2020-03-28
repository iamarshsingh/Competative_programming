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
    string a,b;
    cin>>a>>b;
    int of[26]={0};
    int l = a.length();
    for(int i=0;i<l;i++){
        of[a[i]-'a']++;
    }
    for(int i=0;i<b.length()-l+1;i++){
        int freq[26]={0};
        for(int j=i;j<i+l;j++){
            freq[b[j]-'a']++;
        }
        bool poss=true;
        for(int j=0;j<26;j++){
            if(freq[j]!=of[j]) poss=false;
        }
        if(poss){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}