#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int a,b,D,n,m;
	cin>>n>>m>>D;
	vector<int> arr[n+1];
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	deque<int> d;
	d.push_back(1);
	bool visited[n+1]={false};
	visited[1]=true;
	vector<pair<int,int>> ans;
	bool pos=false;
	while(!d.empty()){
		int curr = d.front();
		d.pop_front();
		for(int i:arr[curr]){
			if(curr==1){
				if(visited[i]==false){
					visited[i]=true;
					d.push_back(i);
					ans.push_back({curr,i});
				}
				if(d.size()==D){
					pos=true;
					break;
				}
			}
			if(visited[i]==false){
				visited[i]=true;
				d.push_back(i);
				ans.push_back({curr,i});
			}
		}
		if(!pos){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}