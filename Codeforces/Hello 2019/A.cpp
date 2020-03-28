#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    char r,s;
    cin>>r>>s;
    char rr,ss;
    for(int i=0;i<5;i++){
        cin>>rr>>ss;
        if(rr==r || ss==s){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
