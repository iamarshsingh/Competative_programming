#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n],val[5005],maxo=0,un=0;
    for(int i=0;i<5005;i++)val[i]=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(val[arr[i]]==0)un++;
        val[arr[i]]++;
        if(val[arr[i]]>maxo)maxo=val[arr[i]];
    }

    if(k>=maxo){
        cout<<"YES"<<endl;
            int ans[5005][k+1];
            for(int i=0;i<5005;i++)
                for(int j=0;j<k+1;j++)
                    ans[i][j]=1;
            for(int i=0;i<k;i++){
                cout<<i+1<<" ";
                ans[arr[i]][i+1]=0;
            }
            for(int i=k;i<n;i++){
                int aaa=0;
                for(int j=1;j<=k;j++){
                    if(ans[arr[i]][j]==1){
                        ans[arr[i]][j]=0;
                        aaa=j;
                        break;
                    }
                }
                cout<<aaa<<" ";
            }

    }
    else{
        cout<<"NO"<<endl;
    }

}
