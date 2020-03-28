#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n][26];
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                arr[i][j]=0;
            }
        }
        string s;
        for(int ii=0;ii<n;ii++){
            cin>>s;
            for(int i=0;i<s.length();i++){
                arr[ii][s[i]-'a']=1;
            }
        }
        bool cas=true;
        int ans=0;
        for(int i=0;i<26;i++){
            cas=true;
            for(int j=0;j<n;j++){
                if(arr[j][i]==0)cas = false;
            }
            if(cas)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
