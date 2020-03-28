#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    int closing[500005],opening[500005];
    int c=0,o=0,full=0;
    for(int i=0;i<500005;i++){
        closing[i]=0;
        opening[i]=0;
    }
    ll ans=0;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        c=0;o=0;
        int len = s.length();
        for(int j=0;j<len;j++){
            if(s[j]=='('){
                o++;
            }
            else if(s[j]==')'){
                if(o>0)o--;
                else c++;
            }
        }
        if(c==0 && o==0){
            if(full>0){
                full--;
                ans++;
            }
            else{
                full++;
            }
        }
        else if(c==0){
            if(closing[o]>0){
                closing[o]--;
                ans++;
            }
            else{
                opening[o]++;
            }

        }
        else if(o==0){
            if(opening[c]>0){
                opening[c]--;
                ans++;
            }
            else{
                closing[c]++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
