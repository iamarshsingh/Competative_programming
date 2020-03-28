#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    string t;
    cin>>t;
    int len=t.length();
    int i = (len%2==0)?((len/2)-1):((len-1)/2);
    string ans=string(1,t[i]);
    i++;
    int j=1;
    while(i<len){
        ans = ans + string(1,t[i]);
        if(len%2==0){
            if(i<len-1) ans = ans + string(1,t[i-(j*2)]);
        }
        else ans = ans + string(1,t[i-(j*2)]);
        j++;
        i++;
    }
    cout<<ans<<endl;
    //cout<<ans[ans.length()-1]<<endl;
}
