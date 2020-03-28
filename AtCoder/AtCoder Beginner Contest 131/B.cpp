#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool comp(int a, int b){
	return abs(a) < abs(b);
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int n,l,ans=0;
	cin>>n>>l;
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i] = l+i;
		ans = ans + arr[i];
	}
	sort(arr,arr+n,comp);
	ans = ans - arr[0];
	cout<<ans<<endl;

	return 0;
}