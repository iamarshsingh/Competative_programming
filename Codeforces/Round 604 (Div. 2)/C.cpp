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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n<10){
        cout<<"0 0 0\n";
        return;
    }
    int h = n/2;
    //cout<<h<<"\n";
    int minn = 0;
    for(int i=h-1; i>=0; i--){
        if(arr[i]!=arr[i+1]){
            minn = i;
            break;
        }
    }
    //cout<<minn<<"\n";
    int g=0,s=0,b=0;
    int i=0;
    for(;i<=minn;i++){
        if(arr[i]!=arr[i+1]){
            break;
        }
    }
    i++;
    g = i;
    for(;i<=minn;i++){
        if(arr[i]!=arr[i+1]){
            if((i+1-g) > g)
                break;
        }
    }
    i++;
    s = (i-g);
    b = (minn-i+1);
    if(g<s && g<b && g>0 && b>0 && s>0){
        cout<<g<<" "<<s<<" "<<b<<"\n";
    }
    else{
        cout<<"0 0 0\n";
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