#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll solve(){
	ll n,s,a,b,ans=0,curr=0;
	cin>>n>>s;
	vector<ll> pwithskill[s+1];
	vector<ll> skillsofp[n+1];
	for(ll i=0;i<n;i++){
		cin>>a;
		for(ll j=0;j<a;j++){
			cin>>b;
			pwithskill[b].push_back(i);
			skillsofp[i].push_back(b);
		}
	}
	vector<int> poss(n,0);
	for(ll i=0;i<n;i++){
		curr=n;
		for(ll j:skillsofp[i]){
			for(ll k:pwithskill[j]){
				poss[k]++;
				if(poss[k]==skillsofp[i].size()) curr--;
			}
		}
		//cout<<curr<<endl;
		ans += curr;
		for(ll j:skillsofp[i]){
			for(ll k:pwithskill[j]){
				poss[k]=0;
			}
		}
	}
	return ans;
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
	for(int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": "<<solve()<<"\n";
	}

	return 0;
}