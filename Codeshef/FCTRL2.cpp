#include <iostream>
using namespace std;
 
int main(){
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
 
    int a[200],carry=0,temp,m=0;
 
    for(int i=0;i<200;i++)a[i]=0;
 
    a[0]=1;
 
    for(int i=2;i<=n;i++){
 
        for(int j=0;j<=m;j++){
            temp = (i*a[j])+carry;
            carry = temp/10;
            a[j]=temp%10;
            if(carry!=0 && j==m){
              m++;
            }
        }
    }
 
    for(int i=m;i>=0;i--)cout<<a[i];
    cout<<endl;
  }
 
 
  return 0;
}
