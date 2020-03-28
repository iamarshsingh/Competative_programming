#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int temp=0,maxx=0;
    for(int i=0;i<n;i++){
        int j=i;
        temp=0;
        while(j<n && s[j]==t[j-i]){
            temp++;
            if(temp>maxx){
                maxx=temp;
            }
            j++;
        }
    }
    cout<<(n-maxx)<<endl;
    return 0;
}