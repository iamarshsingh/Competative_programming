#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		ll temp,sum,maxx=0,i=0,maxind=0;
		while(i<n){
			temp=0;
			sum=0;
			maxx=0;
			maxind=n;
			for(int j=i;j<n;j++){
				temp = (arr[j]/(j-i+1));
				if(temp>=maxx){
					maxx=temp;
					maxind = j+1;
				}
				sum+=temp;
			}
			if(sum<=k){
				cout<<i+1<<endl;
				break;
			}
			else{
				i=maxind;
			}
		}
		//cout<<i<<endl;
		if(i==n){
			cout<<n+1<<endl;
		}
	}

	return 0;
}