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
		int b,p,f,h,c,ans=0;
		cin>>b>>p>>f>>h>>c;
		if(h>c){
			ans += h*min(b/2,p);
			if(p<=(b/2)){
				b -= (2*p);
				ans += c*min(f,b/2);
			}
			else{
				b=0;
			}

		}
		else{
			ans += c*min(b/2,f);
			if(f<=(b/2)){
				b -= (2*f);
				ans += h*min(b/2,p);
			}
			else{
				b=0;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}