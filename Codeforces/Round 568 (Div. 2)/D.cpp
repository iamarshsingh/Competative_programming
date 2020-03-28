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

	ll n;
	cin>>n;
	pair<ll,ll> arr[n];
	ll diff[n-1];
	for(ll i=0;i<n;i++){
		cin>>arr[i].first;
		arr[i].second = i+1;
	}
	if(n<4){
		cout<<arr[0].second<<endl;
		return 0;
	}
	sort(arr,arr+n);
	map<ll,ll> mp;
	ll cnt=0;
	for(ll i=0;i<n-1;i++){
		diff[i] = arr[i+1].first - arr[i].first;
		if(mp.find(diff[i])==mp.end()){
			cnt++;
		}
		mp[diff[i]]++;
	}
	ll maxx=0,dif=0;
	for(auto it:mp){
		if(it.second>=maxx){
			dif = it.first;
			maxx=it.second;
		}
	}
	if(mp.size()==1){
		cout<<arr[0].second<<endl;
		return 0;
	}
	if(mp.size()>3){
		cout<<"-1"<<endl;
		return 0;
	}
	vector<ll> ans;
	//cout<<n<<" "<<dif<<endl;
	for(ll i=0;i<n-1;i++){
		//cout<<i<<": "<<diff[i]<<endl;
		if(diff[i]!=dif){
			if(i<n-2 && diff[i]+diff[i+1]==dif){
				ans.push_back(i+1);
				i++;
			}
			else if(i==0){
				ans.push_back(i);
			}
			else if(i==n-2){
				ans.push_back(n-1);
			}
			else{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	if(ans.size()>1)
	{
		cout<<-1<<endl;
		return 0;
	}
	else{
		cout<<arr[ans[0]].second<<endl;
	}


	return 0;
}