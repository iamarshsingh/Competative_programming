#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;
 
ll minimum(ll a, ll b){
	return (a<b)?a:b;
}

ll maximum(ll a, ll b){
	return (a>b)?a:b;
}

void dfs(vector<vector<ll>> &c, vector<vector<ll>> &hl, vector<ll> &p, vector<ll> &h, ll node,ll par)
{
	p[node]=par;
	if(h[node]==hl.size())
	{
		hl.push_back({});
	}
	hl[h[node]].push_back(node);
	for(ll i:c[node])
	{
		if(i==par)
			continue;
		h[i]=h[node]+1;
		dfs(c, hl, p, h, i,node);
	}
}

ll solve(){
	ll n,x,y;
	cin>>n;
	vector<ll> h(n),a(n),p(n);
	vector<vector<ll>> c(n),hl;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		c[x].push_back(y);
		c[y].push_back(x);
	}
	dfs(c, hl, p, h, 0,-1);
	vector<ll> power1(n),power2(n),power3(n);
	ll m=0;
	for(int i=0;i<n;i++){
		m=maximum(m,h[i]);
	}
	for(ll i=m;i>=0;i--)
	{
		for(ll j:hl[i])
		{
			power1[j]=0;
			power2[j]=a[j];
			power3[j]=a[j];
			bool gre=0;
			for(ll k:c[j])
			{
				if(k==p[j])
					continue;
				if(power3[k]>=maximum(power1[k],power2[k]))
				{
					gre=1;
				}
				power1[j]+=maximum(power1[k],power2[k]);
				power2[j]+=maximum(maximum(power1[k],power2[k]),power3[k]);
				power3[j]+=maximum(maximum(power1[k]+a[k],power2[k]),power3[k]);
			}
			if(gre==0)
			{
				ll mi=INF;
				for(ll k:c[j])
				{
					if(k==p[j])
						continue;
					mi=minimum(mi,maximum(maximum(power1[k],power2[k]),power3[k])-power3[k]);
				}
				power2[j]-=mi;
			}
		}
	}
	return maximum(maximum(power1[0],power2[0]),power3[0]);
}

int main()
{
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": "<<solve()<<"\n";
	}
}