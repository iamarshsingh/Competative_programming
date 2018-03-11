#include <stdio.h>
 
int main(){
 
  int T;
  scanf("%d",&T);
  while(T--){
    int n;
    scanf("%d",&n);
    int A[n],ans,temp;
    for(int i=0;i<n;i++){
      scanf("%d",&A[i]);
      if(i==0){
        temp = A[0];
        ans = i+1;
      }
      if(i>0){
        if(A[i]<temp){
          temp = A[i];
          ans=i+1;
        }
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
