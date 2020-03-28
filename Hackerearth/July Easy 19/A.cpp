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

	int n;
	cin>>n;
	int ans=1;
	for(int i=2;i<n-1;i++){
		if(__gcd(i,n)==1){
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}