#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int big=0,small=0,bi,sm;
    int a,b;
    char temp;
    while(n--){
        cin>>temp>>a>>b;
        if(a>=b){
            bi=a;
            sm=b;
        }
        else{
            bi=b;
            sm=a;
        }

        if(temp=='+'){
            big = max(bi,big);
            small = max(sm,small);
        }
        else{
            if(big<=bi && small<=sm){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}
