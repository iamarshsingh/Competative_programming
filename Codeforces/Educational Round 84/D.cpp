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

vector<int> zero;

bool check(vector<int> arr, vector<int> col){
    int n=arr.size();
    int curr;
    vector<bool> visited(n, false);
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        set<int> cov;
        curr = i;
        visited[curr] = true;
        cov.insert(col[curr]);
        while(visited[arr[curr]]==false){
            curr = arr[curr];
            visited[curr] = true;
            cov.insert(col[curr]);
        }
        // cout<<arr<<" "<<visited<<"\n";
        if(cov.size()==1) return true;
    }
    return false;
}

vector<int> mul(vector<int> a, vector<int> b){
    vector<int> ans(a.size(),0);
    int n = a.size();
    for(int i=0;i<n;i++){
        ans[i] = a[b[i]];
    }
    return ans;
}

vector<int> power(vector<int> arr, int b){
    //cout<<b<<endl;
    vector<int> ans(zero);
    if(b==0) return ans;
    ans = power(arr, b/2);
    
    if(b%2==0){
        return mul(ans, ans);
    }
    else{
        return mul(mul(arr,ans), ans);
    }
}

void solve(){
    int n;
    cin>>n;
    zero.resize(n);
    for(int i=0;i<n;i++) zero[i] = i;
    vector<int> arr(n);
    vector<int> col(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]--;
    }
    for(int i=0;i<n;i++) cin>>col[i];

    //for(int i=0;i<=n;i++){
    //    cout<<i<<" : "<<power(arr,i)<<"\n";
    //}

    int l=1, r=n;
    while(l<r){
        int mid = (l+r)/2;
        if(n>10)
            cout<<mid<<endl;
        if(check(power(arr, mid), col)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l<<"\n";
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}