#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

string prec[]={"1","34","122","1111","11123","111112","1111124","11111113","111111111","1111111114","11111111126","111111111115","1111111111112","11111111111116","111111111111128","1111111111111111","11111111111111113","111111111111111118","1111111111111111122","11111111111111111119","111111111111111111114","1111111111111111111112","11111111111111111111168","111111111111111111111335","1111111111111111111111111","11111111111111111111111126","111111111111111111111111222","1111111111111111111111111113","11111111111111111111111111116","111111111111111111111111111122"};

signed main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int lim=30;
    int lastSum=lim*81+1;
    vector<vector<bool>> f(lim+1,vector<bool>((81*lim)+5,0));
    vector<vector<string>> g(lim+1,vector<string>((81*lim)+5,""));
    for(int i=1;i<=9;++i)
    {
        f[lim-1][i*i]=1;
        g[lim-1][i*i]+=(char('0'+i));
    }
    for(int ix=lim-2;ix>=0;--ix)
    {
        for(int sum=1;sum<lastSum;++sum)
        {
            for(int dig=9;dig>0;--dig)
            {
                if(((sum-(dig*dig))>0)&&(f[ix+1][sum-(dig*dig)]))
                {
                    f[ix][sum]=(f[ix][sum]|f[ix+1][sum-(dig*dig)]);
                    g[ix][sum]=(g[ix+1][sum-(dig*dig)]+char('0'+dig));
                }
            }
        }
    }
    for(int i=0;i<lim+1;++i)
    {
        for(int j=0;j<(81*lim)+5;++j)
        {
            reverse(g[i][j].begin(),g[i][j].end());
        }
    }
    int tt;cin>>tt;
    
    while(tt--)
    {
        int n;cin>>n;
        if(n<lim)
        {
            cout<<prec[n-1]<<"\n";continue;
        } 
        int num=sqrt(n);
        num+=((num*num)!=n);
        string fin="";fin+=char('9'+1);
        while(num<=9000)
        {
            int target=num*num-(n-lim);
            if(target>=lastSum){break;}
            if(f[0][target])
            {
                fin=min(fin,g[0][target]);
            }
            ++num;
        }
        if(fin==""){cout<<-1<<"\n";}
        else{for(int i=0;i<(n-lim);++i){cout<<1;}cout<<fin<<"\n";}
    }
}