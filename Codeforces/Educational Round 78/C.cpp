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
    int a,one=0,two=0;
    map<int,int> left;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==1) one++;
        else two++;
        left[two-one] = i+1;
    }
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    one = two = 0;
    int ans=left[0];
    map<int,int> right;
    for(int i=n-1;i>=0;i--){
        if(arr[i]==1) one++;
        else two++;
        right[one-two] = (n-i);
        if(left.find(one-two)!=left.end()) ans = max(ans, left[one-two]+right[one-two]);
    }
    cout<<(2*n - ans)<<"\n";
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}