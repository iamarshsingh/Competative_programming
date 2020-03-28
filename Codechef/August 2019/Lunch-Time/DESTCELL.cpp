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
		ll n,m,curr=0;
		cin>>n>>m;
		ll grid[n][m];
		for(ll k=1;k<=n*m;k++){
			curr=0;
			for(ll i=0;i<n*m;i+=k){
				grid[i%n][i/n] = k;
				curr++;
			}
			for(ll i=0;i<n*m;i+=k){
				if(grid[i/m][i%m]<k){
					grid[i/m][i%m] = k;
					curr++;
				}
			}
			cout<<curr<<" ";
		}
		cout<<endl;
	}

	return 0;
}