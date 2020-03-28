#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

void solve(){
    int n,a,num=0;
    cin>>n;
    set<int> curr;
    set<int> prev;
    vector<int> ans;
    bool poss=true;
    for(int i=0;i<n;i++){
        cin>>a;
        if(!poss)continue;
        //cout<<"uy "<<a<<"\n";
        if(a>0){
            if(prev.find(a)!=prev.end()){
                //cout<<":h"<<'\n';
                if(curr.empty()){
                    ans.push_back(num);
                    prev.clear();
                    num=1;
                }
                else{
                    poss=false;
                }
            }
            else if(curr.find(a)!=curr.end()){
                //cout<<"hh"<<'\n';
                poss=false;
            }
            else{
                curr.insert(a);
                prev.insert(a);
                num++;
            }
        }
        else{
            a=-1*a;
            if(curr.find(a)==curr.end()){
                poss=false;
            }
            else{
                curr.erase(a);
                num++;
                if(curr.empty()){
                    ans.push_back(num);
                    prev.clear();
                    num=0;
                }
            }
        }
    }
    if(!curr.empty()){
        poss=false;
    }
    if(num>0){
        ans.push_back(num);
    }
    if(!poss){
        cout<<"-1\n";
        return;
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}