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

char sol(char a, char b){
    if(a==b){
        return (char)((a + 1 -'a')%3 + 'a');
    }
    int l = (a-'a')+(b-'a');
    if(l==1) return 'c';
    else if(l==2) return 'b';
    else return 'a';
}

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            if(i>0 && i<n-1){
                if(s[i+1]=='?') s[i] = (s[i-1] + 1 -'a')%3 + 'a';
                else{
                    s[i] = sol(s[i-1], s[i+1]);
                }
            }
            else if(i==0){
                if(n==1) s[i] = 'a';
                else s[i] = (s[i+1] + 1 -'a')%3 + 'a';
            }
            else if(i==n-1){
                s[i] = (s[i-1] + 1 -'a')%3 + 'a';
            }
        }
        if(i<n-1 && s[i]==s[i+1]){
            cout<<"-1\n";
            return;
        }
    }
    cout<<s<<"\n";
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}