#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

int fact(int n){
    for(int i=2;i<=n;i++){
        if(n%i==0)
            return i;
    }
}

void solve(){
    int n,sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    if(sum==1){
        cout<<"-1\n";
        return;
    }
    int curr=0,sf = fact(sum), ans=0;
    vector<int> cas;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            curr++;
            cas.push_back(i);
        }
        if(curr==sf){
            //cout<<cas.size()<<"\n";
            int s = cas.size();
            int minn = INF;
            if(s%2==0LL){
                int h = 0LL;
                int median = ( cas[s/2LL] + cas[s/2LL] ) / 2LL;
                for(int j:cas){
                    h+=abs(j-(median));
                    //cout<<j<<" "<<j<<" "<<(cas[s/2])<<"\n";
                }
                minn = min(h,minn);
            }
            else{
                int h = 0LL;
                int median = ( cas[s/2LL] + cas[s/2LL] ) / 2LL;
                for(int j:cas){
                    h+=abs(j-cas[s/2]);
                }
                minn = min(h,minn);
            }
            curr=0LL;
            ans += minn;
            cas.clear();
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