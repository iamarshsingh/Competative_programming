#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll power(ll a, ll b){
	if(b<=0) return 1;
	ll ans = power(a,b/2);
	if(b%2==0) return ans*ans;
	else return a*ans*ans;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	vector<ll> cubes;
	for(ll i=2; (i*i*i) <= 10000000; i++)
	{
		cubes.push_back((i*i*i));
	}
	int t;
	cin>>t;
	while(t--){
		ll n,curr;
		cin>>n;
		ll arr[n];
		ll ans = power(2,n);
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		if(n==1){
			cout<<ans<<endl;
			continue;
		}
		ll nons = 0, left = n;
		vector<bool> visited(n,false);
		for(ll i=0;i<n;i++){
			curr = arr[i];
			for(ll l=0;l<cubes.size();l++){
				if(curr%cubes[l]==0){
					nons += power(2,left-1) - 1;
					//cout<<"1: "<<nons<<" "<<curr<<endl;
					//poss=true;
					//curr = curr / arr[j];
					visited[i] = true;
					left--;
					break;
				}
			}
		}
		bool poss;
		ll curlef=0,dones=0;
		for(ll i=0;i<n;i++){
			if(visited[i]){
				continue;
			}
			curlef=dones;
			poss = false;
			for(ll j=i+1;j<n;j++){
				if(visited[j]) continue;

				curr = arr[i] * arr[j];
				for(ll l=0;l<cubes.size();l++){
					if(curr%cubes[l]==0){
						nons += power(2,left-curlef-2);
						//cout<<"2: "<<nons<<" "<<curr<<endl;
						poss=true;
						//curr = curr / arr[j];
						break;
					}
				}
				if(poss)curlef++;
			}
			if(poss)dones++;
		}
		//cout<<endl<<ans<<" "<<nons<<endl;
		cout<<(ans-nons)<<endl;
	}

	return 0;
}