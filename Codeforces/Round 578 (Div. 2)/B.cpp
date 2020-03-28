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

	int t;
	cin>>t;
	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;
		ll arr[n];

		for(int i=0;i<n;i++) cin>>arr[i];

		ll curr=m;
		bool poss=true;
		for(int i=1;i<n;i++){
			if(curr+arr[i-1]>=(arr[i]-k)){
				if(arr[i-1]>=(arr[i]-k)){
					curr += (arr[i-1] - max(0LL,(arr[i]-k)));
				}
				else{
					curr -= ((arr[i]-k) - arr[i-1]); 
				}
			}
			else{
				poss=false;
				break;
			}
			//cout<<curr<<endl;
		}
		if(poss){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}

	return 0;
}