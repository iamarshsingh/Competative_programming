#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

int n,m,k;
bool visited[10][10];
vector<vector<char>> arr(10, vector<char>(10));

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

void dfs(int i, int j){
    //cout<<i<<" "<<j<<"\n";
    visited[i][j] = true;
    if(arr[i][j] == 'K') k--;
    for(int c=0;c<4;c++){
        int x = i+dx[c];
        int y = j+dy[c];
        //cout<<"IN: "<<x<<" "<<y<<"\n";
        if(x>=0 && x<n && y>=0 && y<m && arr[x][y]!='#' && !visited[x][y]){
            dfs(x,y);
        }
    }
}

void solve(){
    cin>>n>>m;
    string s;
    k=0;
    pair<int,int> begin;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            arr[i][j] = s[j];
            if(arr[i][j]=='X'){
                begin.first = i;
                begin.second = j;
            }
            if(arr[i][j]=='K') k++;
            visited[i][j] = false;
        }
    }
    dfs(begin.first, begin.second);
    if(k==0)cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
 //   cin>>t;
    while(t--){
        solve();
    }
}