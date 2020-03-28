#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	vector<ll> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr.begin(),arr.end());

	vector<ll>::iterator i,j;
	ll maxx = 0;
	for(i=arr.begin();i!=arr.end();i++){
		j = upper_bound(arr.begin(),arr.end(),*i + 5);
		if(j-i > maxx){
			maxx = j-i;
		}
	}
	cout<<maxx<<endl;
	return 0;
}