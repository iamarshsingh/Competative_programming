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
		int n,m;
		cin>>n>>m;
		int arr[n+1];
		for(int i=1;i<=n;i++) cin>>arr[i];
		int mul[m+1];
		vector<int> ans(n+1,-1);
		for(int i=1;i<=m;i++) cin>>mul[i];
		for(int i=1;i<=min(m,n);i++){
			for(int j=i;j<=n;j+=i){
				if(ans[j]==-1 && arr[j]<=mul[i]){
					ans[j]=i;
				}
				else if(ans[j]!=-1 && arr[j]>=mul[i]){
					break;
				}
			}
		}
		for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	}
 
	return 0;
}