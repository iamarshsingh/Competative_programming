#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1e9+7
#define N 1e6+5
#define INF 1e17
using namespace std;
typedef pair<int, int> pi; 
 
void solve(){
    int n,p,a,curr_t=1000000007;
    cin>>n>>p;
    int ans[n];
 
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    int times[n];
    for(int i=0;i<n;i++){
        cin>>a;
        pq.push({a,i});
        times[i] = a;
        curr_t = min(curr_t, a);
    }
    set<int> s;
    queue<int> q;
    int prevind = n;
    while(!pq.empty() || !s.empty()){
        while(!pq.empty() && pq.top().first<=curr_t){
            pi temp = pq.top();
            //cout<<"temp: "<<temp.first<<" "<<temp.second<<"\n"; 
            if(!s.empty()){
                if((*s.begin())>temp.second){
                    s.insert(temp.second);
                    q.push(temp.second);
                }
                else{
                    temp.first = curr_t+p;
                    pq.pop();
                    pq.push(temp);
                    break;
                }
            }
            else{
                s.insert(temp.second);
                q.push(temp.second);
            }
            pq.pop();
        }
        if(!s.empty()){
            int temp = q.front();
            //cout<<temp<<" "<<curr_t<<"\n";
            prevind = temp;
            q.pop();
            curr_t += p;
            ans[temp] = curr_t;
            s.erase(temp);
        }
        if(s.empty() && !pq.empty()){
            curr_t = max(curr_t, pq.top().first);
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
 
signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}