#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n>2 && m>2){
            cout<<4<<endl;
            for(int i=0;i<n;i++){
                if(i%4==0){
                    cout<<4<<" ";
                    for(int j=0;j<m-1;j++){
                        if(j%4==0 || j%4==1)cout<<"3 ";
                        else cout<<"4 ";
                    }
                }
                else if(i%4==2){
                    cout<<3<<" ";
                    for(int j=0;j<m-1;j++){
                        if(j%4==0 || j%4==1)cout<<"4 ";
                        else cout<<"3 ";
                    }
                }
                else if(i%4==1){
                    for(int j=0;j<m;j++){
                        if(j%4==0 || j%4==1)cout<<"1 ";
                        else cout<<"2 ";
                    }
                }
                else{
                    for(int j=0;j<m;j++){
                        if(j%4==0 || j%4==1)cout<<"2 ";
                        else cout<<"1 ";
                    }
                }
                cout<<endl;
            }
        }
        else if(n==2 && m>2){
            cout<<3<<endl;
            for(int i=0;i<m;i++){
                if(i%6==0 || i%6==1){
                    cout<<"1 ";
                }
                else if(i%6==2 || i%6==3){
                    cout<<"2 ";
                }
                else cout<<"3 ";
            }
            cout<<endl;
            cout<<"2 ";
            for(int i=0;i<m-1;i++){
                if(i%6==0 || i%6==1){
                    cout<<"3 ";
                }
                else if(i%6==2 || i%6==3){
                    cout<<"1 ";
                }
                else cout<<"2 ";
            }
            cout<<endl;
        }
        else if(m==2 && n>2){
            cout<<3<<endl;
            int arr[n][m];
            for(int i=0;i<n;i++){
                if(i%6==0 || i%6==1){
                    arr[i][0]=1;
                }
                else if(i%6==2 || i%6==3){
                    arr[i][0]=2;
                }
                else arr[i][0]=3;
            }
            arr[0][1]=2;
            for(int i=0;i<n-1;i++){
                if(i%6==0 || i%6==1){
                    arr[i+1][1]=3;
                }
                else if(i%6==2 || i%6==3){
                    arr[i+1][1]=1;
                }
                else arr[i+1][1]=2;
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else if(n>2){
            cout<<2<<endl;
            for(int i=0;i<n;i++){
                if(i%4==0 || i%4==1){
                    cout<<"1"<<endl;
                }
                else cout<<"2"<<endl;
            }
        }
        else if(m>2){
            cout<<2<<endl;
            for(int i=0;i<m;i++){
                if(i%4==0 || i%4==1){
                    cout<<"1 ";
                }
                else cout<<"2 ";
            }
            cout<<endl;
        }
        else{
            if(n==2 && m==2){
                cout<<2<<endl;
                cout<<"1 1"<<endl;
                cout<<"2 2"<<endl;
            }
            else if(n==2 && m==1){
                cout<<1<<endl;
                cout<<1<<endl;
                cout<<1<<endl;
            }
            else if(n==1 && m==2){
                cout<<1<<endl;
                cout<<"1 1"<<endl;
            }
            else{
                cout<<1<<endl;
                cout<<1<<endl;
            }
        }
    }
    return 0;
}
