#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int ans = INT_MAX;

void solve(deque<ll> arr, int l, int r, int minn, int total){
	int len = arr.size();
	//cout<<len<<" "<<l<<" "<<r<<endl;
	if(l>r){
		arr.pop_back();
		arr.pop_front();
		arr.push_front(minn);
	}
	else{
		if(r==len-1){
			arr.pop_back();
			arr.pop_back();
			arr.push_back(minn);
		}
		else{
			stack<ll> s;
			while(!s.empty()){
				s.pop();
			}
			for(int i = len-1;i>r;i--){
				s.push(arr[i]);
				arr.pop_back();
			}
			arr.pop_back();
			arr.pop_back();
			arr.push_back(minn);
			while(!s.empty()){
				arr.push_back(s.top());
				s.pop();
			}
		}
	}
	len = arr.size();
	if(len<=1){
		if(total<ans){
			// for(int i=0;i<len;i++){
			// 	cout<<arr[i]<<" ";
			// }
			// cout<<endl;
			ans = total;
		}
		return;
	}
	for(int i=0;i<len;i++){
		solve(arr, i, (i+1)%len, arr[i]+arr[(i+1)%len], total+arr[i]+arr[(i+1)%len]);
	}
}

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
		ans = INT_MAX;
		int n;
		ll pen = 0;
		cin>>n;
		deque<ll> arr(n);
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int i=0;i<n;i++){
			solve(arr, i, (i+1)%n, arr[i]+arr[(i+1)%n], arr[i]+arr[(i+1)%n]);
		}
		cout<<ans<<endl;
	}

	return 0;
}