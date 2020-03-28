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

	int n,a,reps=0;
	cin>>n;
	int arr[n];
	unordered_map<int,int> freq;
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
		freq[arr[i]]++;
		if(freq[arr[i]]==2){
			reps++;
		}
	}

	if(reps==0){
		cout<<0<<endl;
		return 0;
	}

	int minn=n;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(freq[arr[j]]==2){
				reps--;
			}
			freq[arr[j]]--;
			if(reps==0){
				minn = min(minn, j-i+1);
			}
		}
		for(int j=i;j<n;j++){
			if(freq[arr[j]]==1){
				reps++;
			}
			freq[arr[j]]++;
		}
	}
	cout<<minn<<endl;
	return 0;
}