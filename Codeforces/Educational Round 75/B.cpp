#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    int z=0,o=0,ans=0;
    int lensum=0;
    bool odd=false;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<s.length();j++){
            if(s[j]=='0') z++;
            else o++;
        }
        if(s.length()%2==1) odd = true;
        lensum += s.length();
    }
    if(z%2==1 && o%2==1 && !odd)
        cout<<n-1<<"\n";
    else
        cout<<n<<"\n";
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