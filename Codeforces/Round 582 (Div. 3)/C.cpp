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
		ll n,m,temp;
		cin>>n>>m;
		vector<int> diffs;
		diffs.push_back(m%10);
		temp=2*m;
		while(temp%10!=m%10){
			diffs.push_back(temp%10);
			temp += m;
		}
		ll ans = 0;
		ll nums = n/m;
		ll d = diffs.size();
		ll each = (nums/d);
		//cout<<nums<<" ";
		for(int i=0;i<d;i++){
			ans += (each*diffs[i]);
			//cout<<diffs[i]<<" ";
		}
		each = (nums%d);
		for(int i=0;i<each;i++){
			ans += (diffs[i]);
		}
		cout<<ans<<endl;
	}

	return 0;
}