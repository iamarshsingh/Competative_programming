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

typedef struct Node{
    
    map<string, Node*> mp;
    Node(){

    }
} Node;

void ins(string s, int i){

}


void solve(){
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n);
    for(int i=0;i<n;i++){
        ins(s[i], 0);
    }
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}