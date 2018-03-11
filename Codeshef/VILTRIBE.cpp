#include <stdio.h>
#include <iostream>
using namespace std;
 
int main(){
  int T;
  cin>>T;
  while(T--){
    char str[100007];
    char t='0',x='0',y='0';
    cin>>str;
    int i=0,ta=0,tb=0,dot=0;
    t=str[0];
    for(i=0;t!='\0';i++){
      t=str[i+1];
    }
    t='0';
    for(int j=0;j<i;j++){
      t=str[j];
      if(t=='A'){
        ta++;
        if(x=='A')y='A';
        else {x='A';dot=0;}
      }
 
      else if(t=='B'){
        tb++;
        if(x=='B')y='B';
        else {x='B';dot=0;}
      }
 
      else if(t=='.'){
        dot++;
      }
 
      if(x=='A' && y=='A'){
        ta = ta + dot;
        y='0';
        dot=0;
      }
 
      if(x=='B' && y=='B'){
        tb = tb + dot;
        y='0';
        dot=0;
      }
 
    }
 
    cout<<ta<<" "<<tb<<endl;
 
  }
 
  return 0;
}
 
