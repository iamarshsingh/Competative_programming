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
	for(int c=1;c<=t;c++){

		int n,k;
		cin>>n>>k;
		int arr1[n];
		int arr2[n];
		for(int i=0;i<n;i++){
			cin>>arr1[i];
		}
		for(int i=0;i<n;i++){
			cin>>arr2[i];
		}

		ll ans=0;
		int ch,d;
		for(int i=0;i<n;i++){
			ch = arr1[i];
			d = arr2[i];
			for(int j=i;j<n;j++){
				if(arr1[j]>ch){
					ch=arr1[j];
				}
				if(arr2[j]>d){
					d=arr2[j];
				}
				if(abs(ch-d) <= k){
					ans++;
				}
			}
		}
		cout<<"Case #"<<c<<": "<<ans<<endl;
	}

	return 0;
}