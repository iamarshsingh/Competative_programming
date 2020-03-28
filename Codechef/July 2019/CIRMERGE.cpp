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
	freopen("output2.txt", "w", stdout); 
	#endif

	int t;
	cin>>t;
	while(t--){
		int n;
		ll pen = 0;
		cin>>n;
		deque<ll> arr(n);
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		int len = arr.size();
		while(len>1){
			ll minn=INT_MAX, l,r;
			for(int i=0;i<len;i++){
				if(arr[i]+arr[(i+1)%len]<minn){
					minn = arr[i]+arr[(i+1)%len];
					l = i;
					r = (i+1)%len;
				}
			}
			pen += minn;
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
			// for(int i=0;i<len;i++){
			// 	cout<<arr[i]<<" ";
			// }
			// cout<<" "<<pen<<endl;
		}
		cout<<pen<<endl;
	}

	return 0;
}