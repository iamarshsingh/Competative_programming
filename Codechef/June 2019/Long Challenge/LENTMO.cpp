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
		ll k,x,n,a,sum=0,minn=1000000000;
		cin>>n;
		ll arr[n],diff;
		for(ll i=0;i<n;i++){
			cin>>arr[i];
			sum += arr[i];
		}
		cin>>k;
		cin>>x;

		ll pos=0, posnums=0, neg=0, negnums=0;
		for(ll i=0;i<n;i++){
			diff = (arr[i]^x) - (arr[i]);
			if(diff>0){
				pos += diff;
				posnums++;
			}
			else{
				neg += diff;
				negnums++;
			}
			minn = min(abs(diff), minn);
		}
		//cout<<minn<<" "<<pos<<endl;
		if(k==n){
			cout<<max(sum, sum+neg+pos)<<endl;
		}
		else if(k%2==0){
			if(posnums%2==0){
				cout<<(sum+pos)<<endl;
			}
			else{
				cout<<(sum+pos-minn)<<endl;
			}
		}
		else{
			cout<<(sum+pos)<<endl;
		}
	}

	return 0;
}