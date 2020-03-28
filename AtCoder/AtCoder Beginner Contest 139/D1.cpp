#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define MOD 1000000007
using namespace std;
map<pair<int,int>,vector<pair<int,int>>> g;
vector<vector<int>> vis;
map<pair<int,int>, int > dis;
bool dfs(pair<int,int> node)
{
	vis[node.x][node.y]=1;
	dis[node]=0;
	for(auto it:g[node])
	{
		if(vis[it.x][it.y]==1){return 0;}
		else if(vis[it.x][it.y]==0)
		{
			if(dfs(it)==0){return 0;}
		}
		dis[node]=max(dis[node],1+dis[it]);
	}
	vis[node.x][node.y]=2;
	return 1;
}
int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int n;cin>>n;
	for(int i=0;i<n;++i)
	{
		std::vector<int> inp(n-1);
		for(int j=0;j<n-1;++j)
		{
			cin>>inp[j];--inp[j];
		}
		for(int j=1;j<n-1;++j)
		{
			g[{min(i,inp[j-1]),max(i,inp[j-1])}].push_back({min(i,inp[j]),max(i,inp[j])});
		}
	}
	vis.resize(n,vector<int>(n,0));
	int ans=0;
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(!vis[i][j])
			{
				bool b=dfs({i,j});
				if(b==0){cout<<-1;return 0;}
			}
			ans=max(ans,dis[{i,j}]);
		}
	}
	cout<<ans+1;
	return 0;
}