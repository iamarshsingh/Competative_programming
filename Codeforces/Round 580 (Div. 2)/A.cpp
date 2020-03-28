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

	int n,m;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>m;
	int b[m];
	int arr[n+m];
	for(int i=0;i<n;i++) arr[i] = a[i];
	for(int i=0;i<m;i++){
		cin>>b[i];
		arr[i+n] = b[i];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			bool poss=true;
			for(int k=0;k<n+m;k++){
				if(a[i]+b[j]==arr[k]){
					poss=false;
				}
			}
			if(poss){
				cout<<a[i]<<" "<<b[j]<<endl;
				return 0;
			}
		}
	}
	return 0;
}