#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
            long long int n,ans=0;
            cin>>n;
            while(n>0){
                n=(n/5);
                ans=ans+n;
            }
            cout<<ans<<endl;
        }
    return 0;
}
