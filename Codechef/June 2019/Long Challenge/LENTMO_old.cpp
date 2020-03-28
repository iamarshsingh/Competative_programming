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
		ll k,x,n,a,sum=0;
		cin>>n;
		ll arr[n],diff[n];
		for(ll i=0;i<n;i++){
			cin>>arr[i];
			sum += arr[i];
		}
		cin>>k;
		cin>>x;
		for(ll i=0;i<n;i++){
			diff[i] = (arr[i]^x) - (arr[i]);
		}
		sort(diff,diff+n);
		ll prof,start=n,end;
		while(true){
			prof=0;
			end=start-1;
			start=end-k+1;
			if(start<0) break;
			for(ll i = start;i<=end;i++){
				prof += diff[i];
			}
			if(prof>0){
				sum+=prof;
			}
			else{
				break;
			}
		}
		cout<<sum<<endl;
	}

	return 0;
}