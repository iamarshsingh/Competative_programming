#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        int sqrtn = ceil((double)sqrt(n));
        bool primes[sqrtn+1];
        for(int i=0;i<sqrtn+1;i++)primes[i]=true;
        bool p[n-m+1];
        for(int i=0;i<n-m+1;i++)p[i]=true;
        //for(int i=0;i<n-m+1;i++){
            //if(primes[i])cout<<i+m<<endl;
        //}
        //cout<<sqrtn<<endl;
        for(int i=2;i<=sqrtn;i++){
            //cout<<"i:  "<<i<<endl;
            if(primes[i]==false) continue;
            else{
                for(int j=i+i;j<=sqrtn;j=j+i){
                    primes[j]=false;
                }
                //cout<<(i*ceil((double)m/i))<<"  "<<i*floor((double)n/i)<<endl;
                for(int j=(i*ceil((double)m/i)); j<=i*floor((double)n/i); j=j+i){
                    if(j==i)continue;
                    //cout<<"j:  "<<j<<endl;
                    p[j-m]=false;
                }
            }
        }
        //for(int i=2;i<=sqrtn;i++){
            //if(primes[i])cout<<i<<endl;
        //}
        for(int i=0;i<n-m+1;i++){
            if(i+m==1)continue;
            if(p[i])cout<<i+m<<endl;
        }
        cout<<endl;
    }
}
