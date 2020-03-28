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
		ll n,m,a,b,c;
		cin>>n>>m;
		ll ans2[n];
		vector<ll> left;
		ll quan[m+1];
		ll ans=0;
		for(int i=0;i<m;i++){
			cin>>quan[i+1];
		}
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			if(quan[a]>0){
				ans += b;
				quan[a]--;
				ans2[i] = a;
			}
			else{
				ans += c;
				left.push_back(i);
			}
		}
		int quanp = 1;
		for(int i=0;i<left.size();i++){
			while(quan[quanp]==0){
				quanp++;
			}
			quan[quanp]--;
			ans2[left[i]] = quanp;
		}
		cout<<ans<<endl;
		for(int i=0;i<n;i++){
			cout<<ans2[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}