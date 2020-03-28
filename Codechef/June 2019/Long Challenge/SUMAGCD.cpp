#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

//100 50 99
//ans: 149

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
		int n,a;
		cin>>n;
		vector<int> arr;
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end());
		vector<int>::iterator ip; 
  		ip = std::unique(arr.begin(), arr.end()); 
		arr.resize(std::distance(arr.begin(), ip)); 
		//cout<<arr.size()<<endl;
		int ans=0;
		n = arr.size();
		for(int i=n-1;i>=0 && arr[i]>=(arr[n-1]-arr[0]); i--){
			int a = arr[i];
			int b = arr[0];
			for(int j=1;j<n;j++){
				if(j!=i){
					b = __gcd(arr[j],b);
				}
			}
			//cout<<i<<" "<<a<<" "<<b<<endl;
			if(a+b>ans){
				ans = a+b;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}