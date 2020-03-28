#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    char str[n][n];
    string s[n];
    int arr[n];
    bool chk[n];
    for(int i=0;i<n;i++){
        s[i]="";
        chk[i]=false;
        for(int j=0;j<n;j++){
            cin>>str[i][j];
        }
        for(int j=0;j<n;j++){
            s[i]=s[i]+string(1,str[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        arr[i]=0;
        for(int j=0;j<n;j++){
            if(str[i][j]=='T'){
                if(s[i]==s[j]) arr[i]++;
                else{
                    arr[i]=0;
                    break;
                }
            }
        }
    }
    int maxx=0;
    for(int i=0;i<n;i++){
        if(arr[i]>=maxx){
            maxx=arr[i];
        }
    }
    cout<<maxx<<endl;
}
