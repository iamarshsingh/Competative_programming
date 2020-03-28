#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

int poss(int n){
    int ans = 0;
	while(n)
	{
		ans++;
		int x = (int)log2(n);
		n-=(int)pow(2,x);
	}
	return ans;
}

int solve(){
    int n,p;
    cin>>n>>p;
    for(int i=1;i<=10000000;i++){
        n-=p;
		if(i>n)
		    break;
		if(n<=0)
		{
			return -1;
		}
		int c = poss(n);
		if(c<=i)
		{
			return i;
		}
    }
    return -1;
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
}