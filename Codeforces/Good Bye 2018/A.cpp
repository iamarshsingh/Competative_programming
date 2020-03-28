#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;

int main(){
    int y,b,r;
    cin>>y>>b>>r;
    if(r>=y+2){
        if(b>=y+1)cout<<(3*y)+3<<endl;
        else{
            cout<<(3*b)<<endl;
        }
    }
    else{
        if(r<=b+1){
           cout<<(3*r)-3<<endl;
        }
        else{
            cout<<(3*b)<<endl;
        }
    }
    return 0;
}
