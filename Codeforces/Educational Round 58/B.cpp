 #include <bits/stdc++.h>
#define MOD 998244353
#define ll long long
using namespace std;

int main(){
    string s;
    cin>>s;
    ll start=s.length();
    ll endd=-1;
    ll temp=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==91 && temp==0){
            temp=1;
        }
        if(s[i]==58 && temp==1){
            start = i;
            break;
        }
    }
    temp=0;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]==93 && temp==0){
            temp=1;
        }
        if(s[i]==58 && temp==1){
            endd = i;
            break;
        }
    }
    if(start>=endd){
        cout<<-1<<endl;
        return 0;
    }
    //cout<<start<<" "<<endd<<endl;
    ll ans=4;
    for(int i=start+1;i<endd;i++){
        if(s[i]==124){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
