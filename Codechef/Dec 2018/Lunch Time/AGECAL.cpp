#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        ll mnths[n];
        ll d=0;
        ll tot[n+1];
        tot[0]=0;
        for(ll i=0;i<n;i++){
            cin>>mnths[i];
            tot[i+1] = 0;
            tot[i+1] = tot[i]+mnths[i];
            d += mnths[i];
        }
        ll yf,mf,df,yto,mto,dto;
        cin>>yf>>mf>>df;
        cin>>yto>>mto>>dto;
        ll ans=0;
        if(yto%4==0)ans=-1;
        if(yf%4==0)ans++;
        if(yto-yf>=1){
            ans += ((yto-yf-1)*d);
            //cout<<ans<<endl;
            //ll diffyear = yto - yf;
            //ll diff = (yto%4)-(yf%4);
            ll leap = ((int)(yto/4)) - ((int)(yf/4));
            ans += leap;
            //cout<<ans<<endl;
            ans += mnths[mf-1]-df+1;
            //cout<<ans<<endl;
            //for(ll i=mf;i<n;i++){
            //    ans += mnths[i];
            //}
            ans += d - tot[mf];
            ans += tot[mto-1];
            //cout<<ans<<endl;
            //for(ll i=0;i<mto-1;i++){
            //    ans += mnths[i];
            //}
            ans += dto;
            cout<<ans<<endl;
        }
        else{
            ans += mnths[mf-1]-df+1;
            //for(ll i=mf;i<mto-1;i++){
            //    ans += mnths[i];
            //}
            ans += tot[mto-1]-tot[mf];
            ans += dto;
            cout<<ans<<endl;
        }

    }
    return 0;
}
