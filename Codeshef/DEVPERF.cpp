#include<bits/stdc++.h>
using namespace std;
char A[1001][1001];
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
     char A[1001][1001];
     int min_col=1011,min_row=1011,max_row=0,max_col=0;
     int n,m;
     scanf("%d %d",&n,&m);
     int i,j;
     int c=0;
     for(i=1;i<=n;i++)
     { 
        scanf("%s",A[i]);
        for(j=0;j<m;j++)
        {
          if(A[i][j]=='*')
          {
            min_col=min(min_col,j);
            min_row=min(min_row,i);
            max_col=max(max_col,j);
            max_row=max(max_row,i);
            c++;
          }
        }
     }
     int max_value=max(max_col-min_col+1,max_row-min_row+1);
     if(c==0)
     {
     printf("0\n");
     }
     else
     {
       printf("%d\n",(max_value/2)+1);
     }
   }
   return 0;	
} 
