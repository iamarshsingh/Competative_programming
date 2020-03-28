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

	int a,b,n,m;
	cin>>n>>m;
	set<int> arr[n+1];
	int leastdeg[n+1];
	set<pair<int,int>> ans;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a].insert(b);
		arr[b].insert(a);
		ans.insert({min(a,b), max(a,b)});
	}
	for(int i=1;i<=n;i++){
		leastdeg[i] = ceil(arr[i].size()/(2.0));
		//cout<<i<<" : "<<arr[i].size()<<endl;
		//cout<<i<<" : "<<leastdeg[i]<<endl;
	}

	int needed = ceil((n+m)/2.0);
	int i=1;
	set <int>::iterator itr;
	
	while(m>needed && i<=n){
		for(itr = arr[i].begin(); itr != arr[i].end() && arr[i].size() > leastdeg[i]; ++itr) 
		{
			int j = *itr;
			if(arr[j].size()>=leastdeg[j]){
				ans.erase({min(i,j), max(i,j)});
				arr[i].erase(j);
				arr[j].erase(i);
				m--;
			}
			if(m<=needed) break;
		}
		i++;
	}
	cout<<ans.size()<<endl;
	set<pair<int,int>>::iterator it;
	for (auto it = ans.begin(); it != ans.end(); it++) { 
        pair<int,int> x = *it;
        cout<<x.first<<" "<<x.second<<endl;
    }

	return 0;
}