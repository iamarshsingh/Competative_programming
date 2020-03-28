#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,a;
	cin>>n;
	vector<int> arr[n+1];

	for(int i=1;i<=n;i++){
		cin>>a;
		if(a!=-1)arr[a].push_back(i);
	}

	bool visited[n+1]={false};
	int dis[n];
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dis[i]=1;
			queue<int> q;
			q.push(i);
			visited[i]=true;
			while(!q.empty()){
				int curr = q.front();
				q.pop();

				for(int j:arr[curr]){
					q.push(j);
					dis[j]=dis[curr]+1;
					visited[j]=true;
				}
			}
		
		}
	}

	int maxx=0;
	for(int i=1;i<=n;i++)if(dis[i]>maxx) maxx=dis[i];
	cout<<maxx<<endl;
	return 0;
}