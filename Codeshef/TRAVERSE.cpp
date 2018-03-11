#include <stdio.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
            long long int M=0,x=0,y=0,common=0,rem=0;
            scanf("%lld",&M);
            common= M/3;
            rem=M%3;
            x=common;
            y=2*common;
            if(rem==1){
                x++;
            }
            if(rem==2){
                x++;
                y++;
            }
            printf("%lld %lld\n",x,y);
        }
    return 0;
} 
