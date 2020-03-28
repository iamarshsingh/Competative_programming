#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    char arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            if(arr[i][j]=='X'){
                if(arr[i-1][j-1]=='X' && arr[i-1][j+1]=='X' && arr[i+1][j-1]=='X' && arr[i+1][j+1]=='X'){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}
