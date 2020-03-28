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
        int A[n][n],B[n][n],grid[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>A[i][j];
                grid[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>B[i][j];
            }
        }
        bool block=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]==B[i][j]){
                    grid[i][j]=1;
                }
                else if(A[i][j]==B[j][i]){
                    grid[i][j]=-1;
                }
                else{
                    block=true;
                    cout<<"No"<<endl;
                    break;
                }
            }
            if(block)break;
        }
        if(block)continue;
        block=false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(grid[i][j]!=grid[j][i]){
                    block=true;
                    cout<<"No"<<endl;
                    break;
                }
            }
            if(block)break;
        }
        if(block)continue;
        bool swh = false;
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        for(int i=0;i<n;i++){
            swh = false;
            for(int j=i+1;j<n;j++){
                if(grid[i][j]==-1)swh=true;
            }
            if(swh){
                for(int j=0;j<n;j++){
                    if(i==j || (A[i][j]==B[i][j] && A[i][j]==B[j][i]))continue;
                    grid[i][j] = (grid[i][j]==1)?-1:1;
                    grid[j][i] = (grid[j][i]==1)?-1:1;
                }
            }
        }
        block=false;
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==-1){
                    block=true;
                    cout<<"No"<<endl;
                    break;
                }
            }
            if(block)break;
        }
        if(block)continue;
        cout<<"Yes"<<endl;
    }
}
