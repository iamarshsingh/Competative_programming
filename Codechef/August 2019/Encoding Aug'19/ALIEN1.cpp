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
	//cout<<setprecision(17)<<endl; 
	int t;
	cin>>t;
	while(t--){
		ll m,k,x;
		cin>>m>>k>>x;
		//cout<<m<<endl;
		ll l=0,r=1000000000000000000,ans=0;
		while(l<r){
			ll mid = (l+r+1)/2;
			ll des = (2*mid + m);
			if(des%k==0){
				des = ((2*mid + m)/k);
			}
			else{
				des = ((2*mid + m)/k) + 1;
			}
			//cout<<mid<<" "<<(2*mid + m)<<" "<<((double)(2*mid + m))<<endl;
			if(des <= x){
				l = mid;
				ans = mid;
			}
			else r=mid-1;
		}
		if(ans>1000000000){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
		cout<<ans<<endl;
	}

	return 0;
}