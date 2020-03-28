#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll solve(){
	ll n,k,ans;
	cin>>n>>k;
	vector<ll> a(n);
	for(ll i=0; i<n; i++)
	{
		cin>>a[i];
	}
	vector<vector<ll>> dp(1001,vector<ll>(k+1));
	vector<ll> prev(k+1);
	for(ll i=0;i<n;i++)
	{
		vector<vector<ll>> temp(1001,vector<ll>(k+1));
		vector<ll> tempp(k,MOD);
		for(ll x=1;x<=1000;x++)
		{
			for(ll y=0;y<=k;y++)
			{
				if(x==a[i])
				{
					if(y==0)
						temp[x][y]=dp[x][y];
					else
						temp[x][y]=min(dp[x][y],prev[y-1]);
				}
				else
				{
					if(y==0)
					{
						temp[x][y]=dp[x][y]+1;
					}
					else
					{
						temp[x][y]=min(dp[x][y]+1,prev[y-1]+1);
					}
				}
				if(y!=k)
					tempp[y]=min(tempp[y],temp[x][y]);
			}
		}
		prev = tempp;
		dp=temp;
	}
	ans=MOD;
	for(ll i=1;i<=1000;i++){
		for(ll j=0;j<k+1;j++){
			ans=min(ans,dp[i][j]);
		}
	}
			
	return ans;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<": "<<solve()<<"\n";
	}

	return 0;
}