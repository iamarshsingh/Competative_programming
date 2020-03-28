#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    cout<<fixed;
    while(t--){
        ll l,r,d;
        cin>>l>>r>>d;
        if(l>d){
            cout<<d<<endl;
        }
        else if(r%d==0){
            cout<<(r+d)<<endl;
        }
        else{
            cout<<(ll)(ceil(((double)r)/d)*d)<<endl;
        }
    }

    return 0;
}
