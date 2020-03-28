#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

// int fact[1000006][2];
// int ans[1000006];

// void pre(){
// 	for(int i=1;i<1000006;i++){
// 		for(int j=1;j*j<=i;j++){
// 			if(i%j==0){
// 				fact[i][j%2]++;
// 				fact[i][(i/j)%2]++;
// 			}
// 		}
// 		if(abs(fact[i][0]-fact[i][1])<3){
// 			ans[i] = ans[i-1]+1;
// 		}
// 		else{
// 			ans[i] = ans[i-1];
// 		}
// 		//cout<<ans[i]<<endl;
// 	}
// }

int solve(int l, int r){
	int ans = 0;
	int freq[2];
	for(int i=l;i<=r;i++){
		freq[0] = freq[1] = 0;
		for(int j=1;j*j<=i;j++){
			if(i%j==0){
				freq[j%2]++;
				freq[(i/j)%2]++;
			}
		}
		if(abs(freq[0]-freq[1])<3){
			ans++;
		}
		//cout<<ans[i]<<endl;
	}
	return ans;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	//pre();

	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		int l,r;
		cin>>l>>r;
		//cout<<"Case #"<<c<<": "<<(ans[r]-ans[l-1])<<endl;
		cout<<"Case #"<<c<<": "<<solve(l,r)<<endl;
	}

	return 0;
}