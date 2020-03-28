#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define pll pair<pair<int,int>,int>
using namespace std;

bool comp(pll a, pll b){	
	if(a.first==b.first) return a.second>b.second;
	return a.first < b.first;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int n,m;
	cin>>n>>m;
	pll arr[m];
	for(int i=0;i<m;i++){
		cin>>arr[i].second;
		cin>>arr[i].first.first;
		cin>>arr[i].first.second;
		arr[i].first.first--;
		arr[i].first.second--;
	}
	sort(arr,arr+m,comp);

	int ans[n];
	int curr=1000000;
	int cov = 0;
	for(int i=0;i<m;i++){
		//cout<<i<<endl;
		if(cov < arr[i].first.first){
			for(; cov<arr[i].first.first;cov++){
				ans[cov] = curr;
			}
		}
		if(arr[i].second==1){
			//cout<<arr[i].first.first<<" "<<cov<<endl;
			for(int j=arr[i].first.first; j<cov-1;j++){
				if(ans[j]>ans[j+1]){
					//cout<<"ge";
					cout<<"NO"<<endl;
					return 0;
				}
			}
			for(; cov<=arr[i].first.second;cov++){
				ans[cov] = curr;
			}
		}
		else{
			bool poss=false;
			for(int j=arr[i].first.first; j<cov-1;j++){
				if(ans[j]>ans[j+1]){
					poss=true;
				}
			}
			//cout<<cov<<" "<<arr[i].first.second;
			if(cov<=arr[i].first.second){
				if(cov>arr[i].first.first){
					ans[cov-1]=curr;
					ans[cov]=curr-1;
					curr--;
					cov++;
				}
				else if(cov<arr[i].first.second){
					ans[cov]=curr;
					ans[cov+1]=curr-1;
					curr--;
					cov++;
					cov++;
				}
				else{
					cout<<"NO"<<endl;
					return 0;
				}
				poss=true;
			}
			if(!poss){
				cout<<"NO"<<endl;
				return 0;
			}
		}
		//cout<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
		// for(int i=0;i<n;i++){
		// 	cout<<ans[i]<<" ";
		// }
		// cout<<endl;
	}
	if(cov < n){
		for(; cov<n;cov++){
			ans[cov] = curr;
		}
	}

	cout<<"YES"<<endl;
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}