#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int freq[200005][2];

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int n,k;
	cin>>n>>k;
	int arr[n];

	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr, arr+n);

	for(int i=0;i<n;i++){
		int curr = 0;
		while(arr[i]>0){
			if(freq[arr[i]][0]<k){
				freq[arr[i]][0]++;
				freq[arr[i]][1] += curr;
			}
			curr++;
			arr[i] = arr[i]/2;
		}
	}
	//cout<<"here"<<endl;
	int ans=INT_MAX;
	for(int i=0;i<=200000;i++){
		if(freq[i][0]>=k){
			//cout<<
			ans = min(ans, freq[i][1]);
		}
	}
	cout<<ans<<endl;

	return 0;
}