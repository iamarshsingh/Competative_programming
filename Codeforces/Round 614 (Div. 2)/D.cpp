#include <bits/stdc++.h>
#define ld long double
#define MOD 1000000007
#define N 1000006
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

#define int long long int
#define MAXX 1000000000000000000
template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.x<<','<< P.y<<')';}

void solve(){
    int x,y,a1,a2,b1,b2,xx,yy,t;
    cin>>x>>y>>a1>>a2>>b1>>b2;
    map<pair<int,int>, int> mp;
    mp[{x,y}] = 0;
    while((a1*x+b1)<=MAXX && (a2*y+b2)<=MAXX){
        mp[{(a1*x+b1),(a2*y+b2)}] = mp[{x,y}] + ((a1*x+b1)-x) + ((a2*y+b2)-y);
        x = (a1*x+b1);
        y = (a2*y+b2);
    }
    int ans = 0;

    int count=0;
    cin>>xx>>yy>>t;
    for(auto it : mp){
        count++;
        pair<int,int> temp = it.first;
        int dis = abs(xx-temp.first) + abs(yy-temp.second);

        int count2 = 0;
        for(auto it2 : mp){
            if(it2.first>temp) break;
            if(dis + (it.second-it2.second)<=t) {
                ans = max(ans, count-count2);
                int dis2 = dis + (it.second-it2.second);
                
                int count3=0;
                for(auto it3 : mp){
                    if(it3.first<=temp) continue;
                    if(dis2 + (it3.second-it2.second) <= t){
                        count3++;
                        ans = max(ans, count3 + count - count2);
                    }
                    else break;
                }

            }
            //cout<<it<<" "<<it2<<" "<<count<<" "<<count2<<" "<<ans<<"\n";
            count2++;
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