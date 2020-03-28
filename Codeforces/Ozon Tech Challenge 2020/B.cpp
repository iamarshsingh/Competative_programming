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
    string s,curr,newstr;
    cin>>s;
    int len = s.length();
    vector<vector<int>> ans;
    curr=s;
    while(true){
        vector<int> currans;
        len = curr.length();
        int l=0,r=len-1;
        while(l<r){
            if(curr[l]=='(' && curr[r]==')'){
                curr[l] = 'x';
                curr[r] = 'x';
                currans.push_back(l);
                currans.push_back(r);
                l++; r--;
            }
            else if(curr[l]==')') l++;
            else if(curr[r]=='(') r--;
        }
        if(currans.size()==0) break;
        ans.push_back(currans);
        newstr = "";
        for(int i=0;i<len;i++){
            if(curr[i]!='x'){
                newstr += curr[i];
            }
        }
        curr=newstr;
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].size()<<"\n";
        sort(ans[i].begin(), ans[i].end());
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]+1<<" ";
        }
        cout<<"\n";
    }
}

signed main(){
    fastio
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}