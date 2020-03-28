#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

const int N = 500043;
const int K = 750;

int a[N];
int sum[K][K];

int main()
{

	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

    int q;
    cin>>q;
    while(q--)
    {
        int t, x, y;
        cin>>t>>x>>y;
        if(t == 1)
        {
            a[x] += y;
            for(int i = 1; i < K; i++)
                sum[i][x % i] += y;
        }
        else
        {
            if(x >= K)
            {
                int ans = 0;
                for(int i = y; i <= 500000; i += x)
                    ans += a[i];
                cout<<ans<<endl;
            }
            else
                cout<<sum[x][y]<<endl;
        }
    }
    return 0;
}