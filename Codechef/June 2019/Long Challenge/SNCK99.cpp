#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAXX 1000000000000000
using namespace std;

typedef pair<ll, pair<ll,ll> > plll;

/*
template <typename T>
void swap(T &a, T &b){
	T c = a;
	a = b;
	b = a;
}
*/
ll id[1000];

ll root(ll x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void dfs(vector<ll> arr[], vector<ll> &visited, int node, ll col){
	col = (col==1)?2:1;
	for(ll i:arr[node]){
		if(visited[i] == 0){
			visited[i] = col;
			dfs(arr,visited,i,col);
		}
	}
}

void primsMST(vector<pair<ll,ll>> arr[], ll n, vector<ll> ans[]){
	bool visited[n+1]={false};
	priority_queue<plll> Q;
	ll x,y;
	plll p;
	Q.push({0,{1,1}});

	while(!Q.empty())
	{
		p = Q.top();
		Q.pop();
		x = p.second.first;
		// Checking for cycle
		if(visited[x] == true)
			continue;
		if(x!=p.second.second){
			ans[x].push_back(p.second.second);
			ans[p.second.second].push_back(x);
		}
		visited[x] = true;
		for(int i = 0;i < arr[x].size();++i)
		{
			y = arr[x][i].second;
			if(visited[y] == false){
				Q.push({arr[x][i].first,{arr[x][i].second,x}});
			}
		}
	}
}

int main(){
	/*
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif
	*/
	ll n,m,a,b;
	cin>>n>>m;
	vector<ll> stab(n+1);
	vector<ll> cost(m);

	for(int i=1;i<=n;i++) id[i] = i;

	for(ll i=1;i<=n;i++){
		cin>>stab[i];
	}
	for(ll i=0;i<m;i++){
		cin>>cost[i];
	}
	vector<pair<ll,ll>> arr[n+1];
	map<pair<ll,ll>,ll> indices;
	ll mat[n+1][n+1];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			mat[i][j] = MAXX;
		}
	}
	map<ll,pair<ll,ll>> tomat;
	for(ll i=0;i<m;i++){
		cin>>a>>b;
		arr[a].push_back({cost[i],b});
		arr[b].push_back({cost[i],a});
		if(a>b) swap(a,b);
		indices[{a,b}] = i;
		tomat[i] = {a,b};
		mat[a][b] = cost[i];
		mat[b][a] = cost[i];
	}
	//cout<<"here"<<endl;
	vector<ll> adj[n+1];
	primsMST(arr,n,adj);

	vector<ll> visited(n+1,0);
	visited[1] = 1;
	dfs(adj,visited,1,1);

	vector<bool> edgesdone(m,false);


	for(ll i=1;i<=n;i++){
		for(ll j=1;j<i;j++){
			if(visited[i]==visited[j] && mat[j][i]<MAXX){
				if(stab[i]*stab[j] < mat[j][i]){
					cout<<(indices[{j,i}]+1)<<endl<<flush;
					//cout<<"here"<<endl<<flush;
					cin>>a;
					//cout<<"got: "<<a<<endl<<flush;
					if(a==0){
						cin>>a>>b;
						stab[a] = b;
					}
					else if(a==1){
						cin>>a>>b;
						cost[a] = b;
						mat[tomat[a].first][tomat[a].second] = b;
					}
				}
			}
		}
	}

	cout<<-1<<endl<<flush;
	string ans="";
	for(int i=1;i<=n;i++){
		if(visited[i]==1){
			ans+="C";
		}
		else{
			ans+="G";
		}
	}
	cout<<ans<<endl<<flush;

	return 0;
}