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

	int n,x;
	cin>>n>>x;
	ll arr[n];
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>0){
			arr[i] = (arr[i]/x) * x;
		}
		sum+=arr[i];
	}
	cout<<sum<<endl;


	return 0;
}	