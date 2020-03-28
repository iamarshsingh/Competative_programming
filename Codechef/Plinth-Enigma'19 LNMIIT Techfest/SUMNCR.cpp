#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll fact[31];
    fact[0]=1;
    for(ll i=1;i<31;i++){
        fact[i] = fact[i-1]*2;
    }

    int t;
    cin>>t;
    while(t--){
        ll k;
        cin>>k;
        ll arr[k];
        bool even=false;
        for(ll i=0;i<k;i++){
            cin>>arr[i];
            if(arr[i]%2==0){
                even=true;
            }
        }
        if(k==1){

            if(even){
                cout<<1<<endl;
            }
            else{
                ll ans = 1;
                while(arr[0]%2==1){
                    ans = ans * 2;
                    arr[0] = arr[0]/2;
                }
                if(arr[0]>1)
                cout<<ans<<endl;
                else cout<<-1<<endl;
            }
            continue;
        }
        sort(arr,arr+k);
        ll ans=0;
        ll ones=0,tot=0;
        ll minn=fact[30];
        bool sahi=false;
        for(ll i=0;i<k;i++){
            tot++;
            ll ans = 1;
            if(even){
                ans=1;
            }
            else{
                while(arr[i]%2==1){
                    ans = ans * 2;
                    arr[i] = arr[i]/2;
                }
            }
            if(arr[i]>1){
                sahi = true;
                if(ans<minn) minn=ans;
            }
        }

        if(tot%2==0){
            cout<<0<<endl;
        }
        else{
            if(sahi)
            cout<<minn<<endl;
            else cout<<-1<<endl;
        }

    }

}
