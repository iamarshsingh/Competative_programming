#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        ll n,t,x,y,z;
        cin>>n>>t>>x>>y>>z;
        ll a,b;
        b = (2*n) + 1;
        if(t==1){
            if(x==z){
                a = x;
            }
            else if(x<z){
                a = (2*n)-x-1;
            }
            else{
                a = (2*n)-z+1;
            }
        }
        else if(t==3){
            if(x==z){
                a = x;
            }
            else if(x<z){
                a = (2*n)-x+1;
            }
            else{
                a = (2*n)-z-1;
            }
        }
        else{
            if(x==z){
                a = 0;
                b = 1;
            }
            else if(x<z){
                a = (2*n)-(2*x)-1;
            }
            else{
                a = (2*n)-(2*z)-1;
            }
        }

        if(a==0){
            cout<<a<<" "<<b<<endl;
            continue;
        }

        ll temp = gcd(a,b);
        a = a/temp;
        b = b/temp;
        cout<<a<<" "<<b<<endl;
    }
}
