#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int a,b,n,m;
	cin>>n>>m;
	vector<int> arr[n+1];
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	int maxx=0,maxxind=0;
	for(int i=0;i<n+1;i++){
		if(arr[i].size()>maxx){
			maxx=arr[i].size();
			maxxind = i;
		}
	}

	deque<int> d;
	d.push_back(maxxind);
	bool visited[n+1]={false};
	visited[maxxind]=true;
	vector<pair<int,int>> ans;

	while(!d.empty()){
		int curr = d.front();
		d.pop_front();
		for(int i:arr[curr]){
			if(visited[i]==false){
				visited[i]=true;
				d.push_back(i);
				ans.push_back({curr,i});
			}
		}
	}

	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}