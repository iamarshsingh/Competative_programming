#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int n;
	cin>>n;
	pair<int,int> arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].first;
		cin>>arr[i].second;
	}
	sort(arr,arr+n,comp);
	int time=0;
	for(int i=0;i<n;i++){
		time += arr[i].first;
		if(time > arr[i].second){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}