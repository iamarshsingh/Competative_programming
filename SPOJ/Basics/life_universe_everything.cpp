#include <stdio.h>

int main()
{
    int n;
    while(true){
        scanf("%d",&n);
        if(n==42){
            printf("%d\n",n);
            fflush(stdout);
            break;
        }
        else{
           printf("%d\n",n);
           fflush(stdout);
        }
    }
    return 0;
}
