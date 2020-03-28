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
    string s; cin>>s;
    string ans="";
    vector<bool> freq(26,0);
    ans = string(1,s[0]);
    freq[s[0]-'a']=1;
    int curr=0;
    for(int i=1;i<s.length();i++){
        if(curr<ans.length()-1 && curr>0){
            if(ans[curr+1]==s[i]){
                curr++;
            }
            else if(ans[curr-1]==s[i]){
                curr--;
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
        else if(curr<ans.length()-1){
            if(ans[curr+1]==s[i]){
                curr++;
            }
            else if(freq[s[i]-'a']==0){
                ans = string(1,s[i]) + ans;
                freq[s[i]-'a'] = 1;
                
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
        else if(curr>0){
            if(ans[curr-1]==s[i]){
                curr--;
            }
            else if(freq[s[i]-'a']==0){
                ans = ans + string(1,s[i]);
                curr++;
                freq[s[i]-'a'] = 1;
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
        else{
            if(freq[s[i]-'a']==0){
                ans = ans + string(1,s[i]);
                curr++;
                freq[s[i]-'a'] = 1;
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
        //cout<<i<<" : "<<ans<<"\n";
    }
    cout<<"YES\n";
    for(int i=0;i<26;i++){
        if(freq[i]==0)
            ans += string(1,'a'+i);
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