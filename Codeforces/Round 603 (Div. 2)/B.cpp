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
    string s[n];
    map<string,vector<int>> pos;
    for(int i=0;i<n;i++){
        cin>>s[i];
        pos[s[i]].push_back(i);
    }
    map<string,vector<int>>::iterator it;
    it = pos.begin();
    int ans=0;
    while(it!=pos.end()){
        if((*it).second.size()>1){
            int l = (*it).second.size();
            for(int j=l-1;j>0;j--){
                bool poss=false;
                for(int c=0;c<4;c++){
                    for(int d=0;d<10;d++){
                        string temp = s[(*it).second[j]];
                        temp[c] = ( temp[c] - '0' + d)%10 + '0';
                        if(pos.find(temp)==pos.end()){
                            pos[temp].push_back((*it).second[j]);
                            s[(*it).second[j]] = temp;
                            poss=true;
                            (*it).second.pop_back();
                            ans++;  
                            break;
                        }
                    }
                    if(poss) break;
                }
            }
        }
        it++;
    }
    cout<<ans<<"\n";
    for(int i=0;i<n;i++){
        cout<<s[i]<<"\n";
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