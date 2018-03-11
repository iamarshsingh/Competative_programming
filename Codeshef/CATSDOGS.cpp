#include <stdio.h>
 
using namespace std;
 
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        long long int C, D, L;
        scanf("%lld",&C);
        scanf("%lld",&D);
        scanf("%lld",&L);
        if(L%4==0){
            if((L/4)<=(C+D)){
                if(C<=(2*D)){
                    if((L/4)>=D){
                        printf("%s\n","yes");
                    }
                    else printf("%s\n","no");
 
                }
                else if(C>(2*D)){
                    if((L/4)>=(C-D)){
                        printf("%s\n","yes");
                    }
                    else printf("%s\n","no");
                }
            }
            else printf("%s\n","no");
        }
        else printf("%s\n","no");
    }
    return 0;
}
