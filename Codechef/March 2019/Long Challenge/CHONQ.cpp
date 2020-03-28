#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<pair<ll,ll>> nums[100001];
		

int main(){


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	cin>>t;
	while(t--){
		
		ll n,k;
		ll sum=0;
		cin>>n>>k;
		ll arr[n];
		for(ll i=0;i<n;i++){
			cin>>arr[i];
			//cout<<i<<" "<<arr[i]<<endl;
			sum+=(arr[i]/(i+1));
		}
		//cout<<arr[0]<<endl;

		if(sum<=k){
			cout<<1<<endl;
			continue;
		}

		ll adds[n];
		
		for(ll j=0;j<n;j++){
			adds[j]=0;
		}
		//cout<<"here"<<endl;
		//cout<<"here"<<endl;
		/*
		for(ll i=1;i<100001;i++){
			for(ll j=1;j*j<=i;j++){
				ll temp = i/j;
				if(temp==j){
					nums[i].push_back(make_pair(j,j));	
				}
				else{
					nums[i].push_back(make_pair(temp,j));
					nums[i].push_back(make_pair(j,temp));
				}
			}
			//cout<<i<<endl;
			sort(nums[i].begin(),nums[i].end());
		}
		//*/
		for(ll i=1;i<n;i++){

			if(nums[arr[i]].empty()){
				//cout<<"here"<<endl;
				for(ll j=1;j*j<=arr[i];j++){
					ll temp = arr[i]/j;
					if(temp==j){
						nums[arr[i]].push_back(make_pair(j,j));	
					}
					else{
						nums[arr[i]].push_back(make_pair(temp,j));
						nums[arr[i]].push_back(make_pair(j,temp));
					}
				}
				//cout<<i<<endl;
				sort(nums[arr[i]].begin(),nums[arr[i]].end());
			}
			//cout<<sizeof(nums[arr[i]])<<endl;
			ll temp = arr[i]/(i+1);
			//cout<<arr[i]<<": "<<endl;
			for(pair<ll,ll> j:nums[arr[i]]){
				//cout<<"here2"<<endl;
				//cout<<j.first<<" "<<j.second<<endl;
				if(j.first>temp){
					if(i-j.second+1>0){
						adds[i-j.second+1]+=(j.first-temp);
						temp=j.first;
					}
					else{
						//break;
					}
				}
			}
		}
		/*
		for(ll i=0;i<n;i++){
			cout<<adds[i]<<" ";
		}

		cout<<endl;
		*/
		bool poss=true;
		for(ll i=1;i<n;i++){
			sum = sum - arr[i-1] + adds[i];
			if(sum<=k){
				poss=false;
				cout<<i+1<<endl;
				break;
			}
		}
		if(poss){
			cout<<(n+1)<<endl;
		}
		//*/
	}

	return 0;
}