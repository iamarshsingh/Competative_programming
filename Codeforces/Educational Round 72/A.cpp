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
		int a,b,c;
		cin>>a>>b>>c;
		int ans = 0;
		if(a+c<=b){
			cout<<0<<endl;
		}
		else{
			if(a<b+1){
				c -= (b+1-a);
				a = b+1;
			}
			if(c==0){
				cout<<1<<endl;
				continue;
			}
			int l=0, r=c, maxx=0;
			while(l<r){
				int mid = (l+r)/2;
				if(a+mid>b+c-mid){
					r=mid;
				}
				else{
					l=mid+1;
				}
			}
			cout<<max(1, c-r+1)<<endl;
		}
	}

	return 0;
}