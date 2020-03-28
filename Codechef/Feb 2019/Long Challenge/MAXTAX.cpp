#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000021
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll u,v,n,m,k;
        cin>>n>>m>>k;
        ll budget[n];
        ll conn[n][2];
        for(ll i=0;i<n;i++){
            cin>>budget[i];
            conn[i][0]=0;
            conn[i][1]=0;
        }
        for(ll i=1;i<=m;i++){
            cin>>u>>v;
            if(u>v){
                conn[u-1][1]+=-1*i;
                conn[v-1][1]+=i;
            }
            else{
                conn[u-1][0]+=i;
                conn[v-1][0]+=-1*i;
            }
        }
        ll temp=0,temp1=0;
        for(ll i=0;i<n;i++){
            conn[i][0]+=temp;
            temp = conn[i][0];
            conn[i][1]+=temp1;
            temp1 = conn[i][1];
        }
        /*
        for(ll i=0;i<n;i++){
            cout<<conn[i][0]<<" ";
        }
        cout<<endl;
        for(ll i=0;i<n;i++){
            cout<<conn[i][1]<<" ";
        }
        cout<<endl;
        //*/
        vector<ll> breaks;
        for(ll i=0;i<n;i++){
            if(conn[i][0]==0 || conn[i][1]==0) breaks.push_back(i+1);
        }
        //breaks.push_back(n);
        ll prev=0,ans=0;
        for(ll i=0;i<breaks.size();i++){
            ll minn=1000000000000;
            for(ll j=prev;j<breaks[i];j++){
                if(budget[j]<minn)minn=budget[j];
            }
            ans += (minn*(breaks[i]-prev));
            prev = breaks[i];
        }
        cout<<ans<<endl;
    }
}
