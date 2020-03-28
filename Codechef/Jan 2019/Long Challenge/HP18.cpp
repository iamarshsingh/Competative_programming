#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b,temp;
        cin>>n>>a>>b;
        int mula=0, mulb=0, mulc = 0;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(temp%a==0 && temp%b==0)mulc++;
            else if(temp%a==0)mula++;
            else if(temp%b==0)mulb++;
        }
        if(mulc>0)mula++;
        if(mula>mulb){
            cout<<"BOB"<<endl;
        }
        else{
            cout<<"ALICE"<<endl;
        }
    }
}
