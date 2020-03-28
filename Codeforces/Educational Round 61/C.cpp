#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n,q;
	cin>>n>>q;
	int painted[n+1]={0};
	vector<pair<int,int>> arr(q);
	int ans=0;
	for(int i=0;i<q;i++){
		cin>>arr[i].first;
		cin>>arr[i].second;
		painted[arr[i].first-1]++;
		painted[arr[i].second]--;
	}
	
	int curr=0;
	for(int i=0;i<n;i++){
		curr = curr + painted[i];
		painted[i] = curr;
		if(painted[i]>0){
			ans++;
		}
	}
	sort(arr.begin(),arr.end());

	for(int i=1;i<q;i++){
		arr[i].second = max(arr[i-1].second,arr[i].second);
	}

	int diff[q];
	diff[0] = (arr[0].second-arr[0].first+1);
	if(arr[1].first<=arr[0].second){
		diff[0] = diff[0] - (arr[0].second - arr[1].first + 1);
	}
	if(diff[0]<0)diff[0]=0;

	for(int i=1;i<q-1;i++){
		diff[i] = (arr[i].second-arr[i].first+1);
		if(arr[i+1].first<=arr[i].second){
			diff[i] = diff[i] - (arr[i].second - arr[i+1].first + 1);
		}
		if(arr[i-1].second>=arr[i].first){
			diff[i] = diff[i] - (arr[i-1].second - arr[i].first + 1);	
		}
		if(diff[i]<0)diff[i]=0;
	}
	
	diff[q-1] = (arr[q-1].second-arr[q-1].first+1);
	if(arr[q-2].second>=arr[q-1].first){
		diff[q-1] = diff[q-1] - (arr[q-2].second - arr[q-1].first + 1);	
	}
	if(diff[q-1]<0)diff[q-1]=0;


	int minn=INT_MAX,temp;
	for(int i=0;i<q;i++){
		for(int j=i+1;j<q;j++){
			temp = 0;
			if(i!=j-1){
				temp = diff[i] + diff[j];
			}
			else{
				if(i==0){
					temp = min(arr[j+1].first-1,arr[j].second) - arr[i].first + 1;
				}
				else if(j==q-1){
					temp = arr[j].second - max(arr[i-1].second+1,arr[i].first) + 1;
				}
				else{
					temp = min(arr[j+1].first-1,arr[j].second) - max(arr[i-1].second+1,arr[i].first) + 1;
				}
			}
			if(temp<0)temp=0;
			if(temp<minn){
				//cout<<i<<" "<<diff[i]<<" "<<j<<" "<<diff[j]<<" "<<temp<<endl;
				minn=temp;
			}
		}
	}
	//cout<<ans<<endl;
	cout<<ans-minn<<endl;
}