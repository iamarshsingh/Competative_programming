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

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> tail(n);
	int ans=1;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	int len=1, i=1;
	tail[0]=arr[1];
	while(i<n){
		//cout<<i<<endl;
		len=1;
		tail[0] = arr[i];
		i++;
		while(i<n && len<=ans){
			//cout<<"h: "<<i<<endl;
			if(arr[i]>tail[len-1]){
				//cout<<"111"<<endl;
				tail[len++] = arr[i];
			}
			else
			{
				//cout<<"222: "<<i<<endl;
				auto it = find(tail.begin(), tail.begin() + len, arr[i]);
				if (it != tail.begin() + len) { 
                	i++; 
                	continue;
                } 
				it = upper_bound(tail.begin(), tail.begin() + len, arr[i]); 
				*it = arr[i]; 
				//cout<<"222: "<<i<<endl;
			}
			//cout<<"hh: "<<i<<endl;
			i++;
		}
		if(len>ans){
			// for(int l=0;l<len;l++){
			// 	cout<<tail[l]<<" ";
			// }
			// cout<<endl;
			ans++;
		}
	}
	cout<<ans<<endl;

	return 0;
}