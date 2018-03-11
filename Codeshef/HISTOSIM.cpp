#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
            char P[1002],Q[1002];
            string ans="YES";
            scanf("%s",&P);
            scanf("%s",&Q);
 
            for(int i=0;P[i]!='\0';i++){
                for(int j=0;j<i;j++){
                    if(P[i]==P[j]){
                        if(Q[i]!=Q[j]){
                            ans="NO";
                            break;
                        }
                    }
                    if(Q[i]==Q[j]){
                        if(P[i]!=P[j]){
                            ans="NO";
                            break;
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    return 0;
} 
