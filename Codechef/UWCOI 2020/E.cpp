#include <bits/stdc++.h>
#define ld long double
#define MOD 1000000007
#define N 1000006
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

#define int long long int

template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.F<<','<< P.S<<')';}

pair<pair<int,int> ,vector<bool>> solveknap(vector<pair<int,int>> arr, int L){
    int n = arr.size();
    int dp[n+1][L+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=L;j++){
            if (i == 0 || j == 0) 
                dp[i][j] = 0; 

            else if (arr[i - 1].F <= j)
                dp[i][j] = max( arr[i - 1].S + dp[i - 1][j - arr[i - 1].F], dp[i - 1][j] ); 
            else
                dp[i][j] = dp[i - 1][j]; 

        }
    }

    vector<bool> ans(n,false);
    int res = dp[n][L];
    int fres = res;
    int w = L;
    for (int i = n; i > 0 && res > 0; i--) { 
          
        if (res == dp[i - 1][w])  
            continue;         
        else { 
  
            ans[i-1] = true;
            res = res - arr[i - 1].S; 
            w = w - arr[i - 1].F; 
        } 
    }
    return {{fres, w}, ans};
}

void solve(){
    int n,L;
    cin>>n>>L;
    vector<pair<int,int>> arr(n,make_pair(0,0));
    for(int i=0;i<n;i++){
        cin>>arr[i].F>>arr[i].S;
    }
    //cout<<arr<<"\n";
    pair<pair<int,int> , vector<bool>> curr = solveknap(arr, L);
    int ans = 0;
    ans += curr.F.F;
    int left1 = curr.F.S;
    //cout<<curr<<"\n";

    vector<pair<int,int>> arr2;
    for(int i=0;i<n;i++){
        if(!curr.S[i]){
            arr2.push_back(arr[i]);
        }
    }
    pair<pair<int,int>, vector<bool>> curr2 = solveknap(arr2, L);
    vector<pair<int,int>> arr3;
    for(int i=0;i<arr2.size();i++){
        if(!curr2.S[i]){
            arr3.push_back(arr2[i]);
        }
    }

    ans += curr2.F.F;
    int left2 = curr2.F.S;
    int left = min(left1, left2);
    sort(arr3.begin(), arr3.end());
    for(int i=arr3.size()-1;i>=0;i--){
        if(arr3[i].S<2 && left>0){
            ans += arr3[i].F;
            left--;
        }
    }
    cout<<ans<<"\n";
}


signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}