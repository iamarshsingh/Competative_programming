#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,frnt=0,back=0;
        cin>>n;
        int flen[n],glen[n];
        for(int i=0;i<n;i++){
            cin>>flen[i];
        }
        for(int i=0;i<n;i++){
            cin>>glen[i];
        }
        for(int i=0;i<n;i++){
            if(flen[i]<=glen[i])frnt++;
            if(flen[i]<=glen[n-i-1])back++;
        }
        if(frnt==n && back==n)cout<<"both"<<endl;
        else if (frnt==n) cout<<"front"<<endl;
        else if(back==n)cout<<"back"<<endl;
        else cout<<"none"<<endl;
    }
    return 0;
} 
