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

void solve(){
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++) cin>>s[i];
    vector<vector<int>> matsum(n+1, vector<int>(n+1,0));
    matsum[1][1] = ((s[0][0]=='1')?1:0);
    for(int i=1;i<n;i++){
        matsum[i+1][1] = matsum[i][1] + ((s[i][0]=='1')?1:0);
        matsum[1][i+1] = matsum[1][i] + ((s[0][i]=='1')?1:0);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            matsum[i+1][j+1] = matsum[i+1][j] + matsum[i][j+1] - matsum[i][j] + ((s[i][j]=='1')?1:0);
        }
    }
    bool case1=true;
    for(int i=1;i<=n;i++){
        if(matsum[i][i]!=i){
            case1=false;
        }
    }
    if(case1){
        cout<<((n*(n+1))/2)<<"\n";
        return;
    }
    //cout<<matsum<<"\n";
    int curr = 0,ans=0;
    for(int size=1; size<=n;size++){
        for(int row=1;row<=n-size+1; row++){
            for(int col=1; col<=n-size+1; col++){

                curr = matsum[row+size-1][col+size-1] - matsum[row-1][col+size-1] - matsum[row+size-1][col-1] + matsum[row-1][col-1];
                //cout<<row<<" "<<col<<" "<<size<<" "<<curr<<"\n";
                if(curr==size) ans++;

            }
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}