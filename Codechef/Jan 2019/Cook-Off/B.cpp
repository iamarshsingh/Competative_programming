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
                if(!( (A[i][j]==B[i][j] && A[j][i]==B[j][i]) || (A[i][j]==B[j][i] && A[j][i]==B[i][j]) )){
                    block=true;
                    cout<<"No"<<endl;
                    break;
                }
            }
            if(block)break;
        }
        if(block)continue;
        int temp;
        bool swh;
        for(int i=0;i<n;i++){
            swh = false;
            for(int j=0;j<n;j++){
                if(A[i][j]!=B[i][j]){
                    swh=true;
                    break;
                }
            }
            if(swh){
                for(int j=0;j<n;j++){
                    temp = A[i][j];
                    A[i][j] = A[j][i];
                    A[j][i] = temp;
                }
            }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<B[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]!=B[i][j]){
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
