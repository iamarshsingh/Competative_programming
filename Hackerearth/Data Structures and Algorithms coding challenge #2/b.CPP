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
	deque<vector<ll>> arr;
	bool left=false, right=false;
	while(q--){
		cin>>c>>x;
		if(c==1){
			vector<ll> freq(32,0);
			curr=31;
			while(curr>=0 && x>0){
				if(x%2==1)freq[curr] = -1;
				x = x/2;
				curr--;
			}
			if(left){
				for(ll i=0;i<32;i++){
					freq[i] += arr[0][i];
				}
			}
			left=true;
			arr.push_front(freq);
		}
		else if(c==2){
			vector<ll> freq(32,0);
			curr=31;
			while(curr>=0 && x>0){
				if(x%2==1)freq[curr] = 1;
				x = x/2;
				curr--;
			}
			if(right){
				ll len = arr.size();
				for(ll i=0;i<32;i++){
					freq[i] += arr[len-1][i];
				}
			}
			right=true;
			arr.push_back(freq);
		}
		else{
			cin>>y;
			cout<<x<<" "<<y<<endl;
			for(int i=0;i<arr.size();i++){
				for(ll j=0;j<32;j++){
					cout<<arr[i][j]<<" ";
				}
				cout<<endl;
			}
			vector<ll> freq(32,0);
			ll ans = 0;
			for(ll i=0;i<32;i++){
				ans = ans*2;
				if(y>x) freq[i] = arr[y-1][i] - arr[x-1][i];
				else freq[i] = arr[y-1][i];
				freq[i] = abs(freq[i]);
				if(freq[i]%2==1){
					ans = ans + 1;
				}
			}
			cout<<ans<<endl;
		}
	}

	return 0;
}