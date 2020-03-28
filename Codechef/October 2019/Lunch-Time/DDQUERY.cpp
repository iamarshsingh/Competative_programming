#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1003
#define INF 1000000000000000000
using namespace std;

int dis[N][N];

void solve(){
    int n,q,a,b,da,db;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }
    vector<int> arr[n+1];
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        queue< pair<int,int> > q;
        q.push({i,0LL});
        //cout<<i<<endl;
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            //cout<<temp.first<<" "<<temp.second<<endl;
            for(int j:arr[temp.first]){
                if(temp.second+1<dis[i][j]){
                    dis[i][j] = min(dis[i][j], temp.second+1);
                    q.push({j, temp.second+1});
                }
            }
        }
    }
    while(q--){
        cin>>a>>da>>b>>db;
        bool poss=false;
        for(int i=1;i<=n;i++){
            if(dis[i][a]==da && dis[i][b]==db){
                cout<<i<<"\n";
                poss=true;
                break;
            }
        }
        if(!poss){
            cout<<-1<<"\n";
        }
    }
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