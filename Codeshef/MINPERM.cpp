#include <stdio.h>
 
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
 
    int n;
    scanf("%d",&n);
    int A[n];
 
    if(n%2==0){
      for(int i=0;i<n;i++){
        if(((i+1)%2)==1){
          A[i]=i+2;
        }
        else {
          A[i]=i;
        }
      }
    }
    else{
      for(int i=0;i<(n-2);i++){
        if(((i+1)%2)==1){
          A[i]=i+2;
        }
        else {
          A[i]=i;
        }
      }
      A[n-2]=n;
      A[n-1]=n-2;
 
 
    }
    
    for(int i=0;i<n;i++){
      printf("%d ",A[i]);
    }
	printf("\n");
  }
 
  return 0;
}
