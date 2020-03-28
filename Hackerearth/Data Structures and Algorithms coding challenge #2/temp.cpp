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

	ll q,c,x,y,curr;
	cin>>q;
	deque<ll> arr;
	while(q--){
		cin>>c>>x;
		if(c==1){
			arr.push_front(x);
		}
		else if(c==2){
			arr.push_back(x);
		}
		else{
			cin>>y;
			curr = 0;
			for(int i=x-1;i<y;i++){
				curr = curr^arr[i];
			}
			cout<<curr<<"\n";
		}
	}
	return 0;
}