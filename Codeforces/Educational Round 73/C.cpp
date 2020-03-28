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
		int c,m,e;
		cin>>c>>m>>e;
		int l = max(c,m) - min(c,m);
		e += l;	
		int maxx = min(c,m);
		if(maxx>e){
			int diff = ceil( (maxx-e)/(3.0) );
			e += (2*diff);
			maxx -= diff;
		}
		cout<<min(maxx, e)<<"\n";
	}	

	return 0;
}