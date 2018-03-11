#include <iostream>
#include<sstream>
using namespace std;
 
int main(){
    int T,same;
    string p1[4],p2[4],ans="";
    cin>>T;
    for(int i=1;i<=T;i++){
 
        same=0;
        for(int j=0;j<4;j++){
            cin>>p1[j];
        }
 
        for(int j=0;j<4;j++){
            cin>>p2[j];
        }
 
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(p1[j]==p2[k])same++;
            }
        }
 
        if(same>=2)ans=ans+"similar"+"\n";
        else ans=ans+"dissimilar"+"\n";
 
    }
 
    cout<<ans;
    return 0;
}
