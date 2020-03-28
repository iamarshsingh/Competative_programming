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
 
	int n,k;
	cin>>n>>k;
	int arr[n];
	vector<bool> poss(k,false);
	vector<bool> dig(k,true);
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		//cout<<arr[i]<<endl;
		arr[i] = arr[i]%k;
		int curr=arr[i];
		poss[curr]=true;
		if(dig[arr[i]]){
			curr = (curr+arr[i])%k;
			while(curr!=arr[i]){
				poss[curr]=true;
				curr = (curr+arr[i])%k;
			}
		}
		if(arr[i]!=0){
			if(dig[arr[i]]){
				for(int j=arr[i];j<k;j+=arr[i]){
					dig[j]=false;
					//cout<<j<<endl;
				}
			}
		}
		else dig[0] = false;
	}
	int ans=0;
	for(int i=0;i<k;i++){
		if(poss[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<k;i++){
		if(poss[i]){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}