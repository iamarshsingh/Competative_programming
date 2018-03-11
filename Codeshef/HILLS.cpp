#include <iostream>
using namespace std;
 
int main(){
  int T;
  cin>>T;
  while(T--){
    int n,u,d,para=1;
    cin>>n>>u>>d;
    int arr[n],total=1;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){
          if((arr[i]-arr[i-1])<=u){
            total++;
          }
          else{
            break;
          }
        }
        else{
          if((arr[i-1]-arr[i])>d){
            para--;
            if(para<0)break;
          }
          total++;
        }
 
    }
    cout<<total<<endl;
  }
  return 0;
}
