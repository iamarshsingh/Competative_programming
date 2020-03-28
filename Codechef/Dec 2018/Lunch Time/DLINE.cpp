#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;
ll ymax=-1;

ll solve( vector<ll> pl[2002], ll go, ll p, ll ans, ll x ){
    ll temp=0;
    //cout<<go<<" "<<p<<"  "<<ans<<" "<<x<<endl;
    if(p<=0){
        return ans;
    }

    while(pl[go].size()==0){
        p--;
        go++;
        if(go>ymax || p<0){
            //cout<<"yes"<<endl;
            return ans;
        }
    }

    temp = pl[go][pl[go].size()-1];
    pl[go].pop_back();
    if(pl[go].size()==0){
        p = p-(temp);
        if(p>=0){
            ans++;
            p = p + temp - 1;
            //cout<<"a: "<<endl;
            ll a = solve(pl, go+1, p-(2*temp), ans, 0);
            //cout<<"a end"<<endl<<"b:"<<endl;
            ll b = solve(pl, go+1, p, ans-x, 0);
            //cout<<"b end"<<endl;
            return max(a,b);
        }
        else{
            p = p + (temp) - 1;
            //cout<<"c: "<<endl;
            return solve(pl, go+1,p, ans, 0);
        }
    }
    else {
        p = p-(temp);
        if(p>=0){
            ans++;
            //cout<<"d:"<<endl;
            ll d = solve(pl, go, p+(temp), ans, ++x);
            //cout<<"d end"<<endl<<"e:"<<endl;
            ll e = solve(pl, go+1, p-temp-1, ans, 0);
            //cout<<"e end"<<endl;
            return max(d, e);
        }
        else{
            //cout<<"f: "<<endl;
            return solve(pl, go+1,p+temp-1,ans, 0);
        }
    }

}

int main(){
    int T;
    cin>>T;
    while(T--){
        ll n,p,y,s,e;
        cin>>n>>p;
        vector<ll> pl[2002];
        for(int i=0;i<2002;i++)pl[i].clear();
        for(int i=0;i<n;i++){
            cin>>y>>s>>e;
            if(y>ymax)ymax=y;
            pl[y].push_back(e);
        }
        for(int i=0;i<2002;i++)sort(pl[i].begin(),pl[i].end(),greater<int>());
        ll ans = 0;
        ans = solve(pl,0,p,ans,0);
        cout<<ans<<endl;
    }
    return 0;
}
