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

	ll n,m,l,r,k;
	cin>>n>>m>>l>>r>>k;
	ll temp = n%m;
	ll anssize = 0;
	vector<ll> ans;
	if(m>n && r>n){
		if(l>n) anssize += (r-l+1);
		else anssize += (r-n);
		if(m<=r && m>=l) anssize--;
		if(anssize<k){
			for(ll i=max(n+1,l);i<=r;i++){
				if(i!=m) ans.push_back(i);
			}
		}
	}
	else{
		for(ll i=1;i*i<=(n-temp);i++){
			//cout<<i<<endl;
			if(i==m) continue;
			//cout<<i<<" "<<n%i<<endl;
			if(n%i==temp && i>=l && i<=r){
				//cout<<n%i<<" "<<temp<<endl;
				anssize++;
				if(anssize<=k) ans.push_back(i);
				ll c = (n-temp)/i;
				if(c==m) continue;
				if((n%c)==temp && c>=l && c<=r){
					//cout<<n%i<<" "<<temp<<endl;
					anssize++;
					if(anssize<=k) ans.push_back(c);
				}
			}
		}
	}
	cout<<anssize<<endl;
	if(anssize>k){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}