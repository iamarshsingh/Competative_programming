#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

typedef pair<ll,ll> pll;

ll n;

ll dfs(vector<ll> arr[], map<pll,ll> &edges, bool visited[] , ll node){
	ll ans = 0,temp=0;
	for(ll i:arr[node]){
		if(visited[i]==false){
			visited[i] = true;
			temp = dfs(arr,edges,visited,i);
			edges[{node,i}] = temp;
			edges[{i,node}] = n-temp;
			ans += temp;
		}
	}
	return ans + 1;
}

bool comp(pair<pll,ll> a, pair<pll,ll> b){
	if(a.first.first == b.first.first){
		return a.first.second < b.first.second;
	}
	return a.first.first < b.first.first;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		ll q,a,b;
		cin>>n>>q;
		vector<ll> arr[n+1];
		for(int i=0;i<n-1;i++){
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		map<pll,ll> edges;
		bool visited[n+1]={false};
		visited[1]=true;

		dfs(arr,edges,visited,1);
		// map<pll,ll>::iterator it;
		// for(auto it = edges.begin(); it!=edges.end();it++){
		// 	cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl;
		// }

		vector<pair<pll,ll>> queries;
		for(ll i=0;i<q;i++){
			cin>>a>>b;
			if(a>b) swap(a,b);
			queries.push_back({{a,b},i});
		}

		sort(queries.begin(), queries.end(), comp);

		map<pll,ll> answers;

		
	}

	return 0;
}