#include <bits/stdc++.h>
#define ll unsigned long long int
#define MOD 1000000007
using namespace std;

vector<ll> numfreq[100];

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	ll n,a;
	cin>>n;
	ll freq[100]={0};
	for(ll i=0;i<100;i++){
		numfreq[i].clear();
	}
	for(ll i=0;i<n;i++){
		cin>>a;
		if(a==0){
			i--;
			n--;
			continue;
		}
		ll curr=0;
		while(a>0){
			//cout<<a<<endl;
			if(a%2==1){
				//cout<<"yes"<<endl;
				freq[curr]++;
				numfreq[curr].push_back(i);
			}
			curr++;
			a = a/2;
		}
	}
	// if(zer>2){
	// 	cout<<3<<endl;
	// 	return 0;
	// }
	for(ll i=0;i<100;i++){
		//cout<<i<<" "<<freq[i]<<endl;
		if(freq[i]>2){
			cout<<3<<endl;
			return 0;
		}
	}
	//cout<<"here"<<endl;
	vector<ll> arr[n];

	for(ll i=0;i<100;i++){
		//cout<<i<<" "<<freq[i]<<endl;
		for(int j=0;j<freq[i];j++){
			for(int k=j+1;k<freq[i];k++){
				arr[numfreq[i][j]].push_back(numfreq[i][k]);
				arr[numfreq[i][k]].push_back(numfreq[i][j]);
			}
		}
	}

	ll ans=MOD;
	for(ll i=0;i<n;i++){
		//cout<<"i: "<<i<<endl;
		vector<ll> parent(n,-1);
		vector<ll> d(n,MOD);
		d[i]=0;
		queue<ll> q;
		while(!q.empty()) q.pop();
		q.push(i);

		set<ll> s;
		s.clear();

		while(!q.empty()){
			ll curr = q.front();
			//cout<<curr<<endl;
			q.pop();
			s.insert(curr);

			for(ll j:arr[curr]){
				if(j==parent[curr] || j==curr) continue;
				else if(s.find(j)!=s.end()){
					ans = min(ans, d[curr]+d[j]+1);
				}
				else{
					parent[j] = curr;
					d[j] = d[curr]+1;
					q.push(j);
				}
			}
		}
	}

	if(ans==MOD){
		cout<<-1<<endl;
	}
	else{
		cout<<ans<<endl;
	}

	return 0;
}