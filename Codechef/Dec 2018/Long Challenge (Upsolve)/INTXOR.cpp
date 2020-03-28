#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int xors[n];
        int arr[n];
        for(int i=0;i<n-2;i++){
            printf("1 %d %d %d",i+1,i+2,i+3);
            cout<<endl<<flush;
            cin>>xors[i+2];
        }
        printf("1 %d %d 1",n-1,n);
        cout<<endl<<flush;
        cin>>xors[0];
        printf("1 %d 1 2",n);
        cout<<endl<<flush;
        cin>>xors[1];
        cout<<2<<" ";
        for(int i=0;i<n-2;i++){
            cout<<(xors[i]^xors[i+1]^xors[i+2])<<" ";
        }
        cout<<(xors[n-2]^xors[n-1]^xors[0])<<" ";
        cout<<(xors[n-1]^xors[0]^xors[1])<<endl<<flush;
    }
    return 0;
}
