#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

#define vvl vector<vector<int>>

void printmat(vvl a){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

vvl matmul(vvl a, vvl b){
    vvl ans(4, vector<int>(4,0));
    //cout<<"inmul"<<"\n";
    //printmat(a);
    //printmat(b);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                ans[i][j] += a[i][k]*b[k][j];
            }
            ans[i][j] %= MOD;
        }
    }
    //printmat(ans);
    //cout<<"\n";
    return ans;
}

vvl power(vvl a, int b){
    vvl ans(4, vector<int>(4,0));
    ans[0][0] = ans[1][1] = ans[2][2] = ans[3][3] = 1;
    //printmat(ans);
    while(b>0){
        if(b&1)
            ans = matmul(ans,a);
        
        b = b>>1;
        a = matmul(a,a);
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vvl a(4, vector<int>(4,0));
    a[0][0] = a[0][2] = a[2][2] = 2;
    a[0][1] = a[0][3] = a[2][3]  = 3;
    a[1][0] = a[3][2] = 1;
    //printmat(a);
    a = power(a, n-1);
    //printmat(a);
    cout<<(a[0][0]*2LL + (a[0][1]+a[0][2]+a[0][3]))%MOD<<"\n";
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