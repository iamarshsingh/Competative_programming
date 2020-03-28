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

	cout<<setprecision(12)<<fixed;

	int t;
	cin>>t;
	while(t--){
		long double x1,y1,r1,x2,y2,r2,l;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		l = sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) );
		if(l + r1 <= r2){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			long double ans1, ans2;
			ans1 = x1 - ((r1/l) * (x2-x1));
			ans2 = y1 - ((r1/l) * (y2-y1));
			cout<<ans1<<" "<<ans2<<endl;
		}
	}

	return 0;
}