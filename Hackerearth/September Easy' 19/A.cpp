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

	int n,k;
	cin>>n>>k;
	int arr[n];
	set<int> s;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		s.insert(arr[i]);
	}
	ll sum=0;
	for(int i=0;i<n;i++){
		//cout<<distance(s.upper_bound(arr[i]), s.end())<<endl;
		sum += (distance(s.upper_bound(arr[i]), s.end())>=k)?arr[i]:0;
	}
	cout<<sum<<endl;

	return 0;
}