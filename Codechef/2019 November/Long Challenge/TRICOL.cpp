#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

char difffrom(char a, char b){
    if( ( a=='R' && b=='G' ) || ( a=='G' && b=='R' ) ) return 'B';
    else if( ( a=='R' && b=='B' ) || ( a=='B' && b=='R' ) ) return 'G';
    else return 'R';
}

void solve(){
    int n,m;
    cin>>n>>m;
    int x,y,p,q;
    cin>>x>>y>>p>>q;
    char colour[n];
    for(int i=0;i<n;i++) cin>>colour[i];
    pair<int,int> coor[n];
    for(int i=0;i<n;i++){
        cin>>coor[i].first>>coor[i].second;
    }
    int a1,a2,a3;
    char diff[3] = {'R', 'G', 'B'};
    deque<pair<pair<int,int>,int>> ugly;
    for(int i=0;i<n;i++){
        cin>>a1>>a2>>a3;
        if(colour[a1]==colour[a2] || colour[a1]==colour[a3] || colour[a2]==colour[a3]){
            ugly.push_back({{a1,a2},a3});
        }
    }
    int ans=0, l = ugly.size();
    while( (l>0 && p>0) && ( (l*l)-((l-1)*(l-1)) ) > (2*x) ){
        pair<pair<int,int>,int> temp = ugly[0];
        ugly.pop_front();
        if(colour[temp.first.first] == colour[temp.first.second] && colour[temp.first.first] == colour[temp.second]){
            if(p<2) break;
            for(int i=0;i<3;i++){
                if(colour[temp.first.first]==diff[i]){
                    colour[temp.first.first]=diff[(i+1)%3];
                    colour[temp.first.second]=diff[(i+2)%3];
                    break;
                }
            }
            p-=2;
        }
        else if(colour[temp.first.first] == colour[temp.first.second]){
            colour[temp.first.first] = difffrom(colour[temp.first.second], colour[temp.second]);
            p--;
        }
        else if(colour[temp.first.first] == colour[temp.second]){
            colour[temp.first.first] = difffrom(colour[temp.first.second], colour[temp.second]);
            p--;
        }
        else{
            colour[temp.first.second] = difffrom(colour[temp.first.first], colour[temp.second]);
            p--;
        }
        l--;
        ans++;
    }
    cout<<ans<<" 0\n";
    for(int i=0;i<n;i++) cout<<colour[i];
    cout<<"\n";
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}