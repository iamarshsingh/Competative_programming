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
		int n;
		cin>>n;
		int arr1[n], arr2[n];
		int freq1[n+1], freq2[n+1];
		for(int i=0;i<n;i++){
			cin>>arr1[i];
			freq1[i+1]=0;
			freq2[i+1]=0;
		}
		for(int i=0;i<n;i++){
			cin>>arr2[i];
		}
		int cov = 0;
		bool poss=false;
		for(int i=0;i<n;i++){
			freq1[arr1[i]]++;
			freq2[arr2[i]]++;

			if(i>0){
				if(arr2[i]<arr2[i-1]){
					sort(arr1+cov, arr1+i);
					sort(arr2+cov, arr2+i);
					for(;cov<i;cov++){
						if(arr1[cov]!=arr2[cov]){
							poss=true;
							break;
						}
					}
				}
			}

			if(poss) break;
		}
		sort(arr1+cov, arr1+n);
		sort(arr2+cov, arr2+n);
		for(;cov<n;cov++){
			if(arr1[cov]!=arr2[cov]){
				poss=true;
				break;
			}
		}
		if(poss){
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}

	return 0;
}