#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll XOR(ll n)
{
    switch(n & 3)
    {
    case 0: return n;     // if n is multiple of 4
    case 1: return 1;     // If n % 4 gives remainder 1
    case 2: return n + 1; // If n % 4 gives remainder 2
    case 3: return 0;     // If n % 4 gives remainder 3
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll ans = XOR(a-1) ^ XOR(b);
        if(ans%2==0){
            cout<<"Even"<<endl;
        }
        else cout<<"Odd"<<endl;
    }
}
