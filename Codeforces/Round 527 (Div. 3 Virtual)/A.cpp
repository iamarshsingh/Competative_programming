#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int c = n/k;
        string ans = "";
        for(int i=0;i<k-1;i++){
            ans = ans + string(c,('a'+i));
        }
        ans = ans + string((c+(n%k)),('a'+k-1));
        cout<<ans<<endl;
    }
}
