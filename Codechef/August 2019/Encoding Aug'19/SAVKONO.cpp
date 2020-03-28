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

	int t;
	cin>>t;
	while(t--){
		int n,z,a;
		cin>>n>>z;
		priority_queue<int> pq;
		for(int i=0;i<n;i++){
			cin>>a;
			pq.push(a);
		}
		int ans = 0;
		while(pq.size()>0 && z>0){
			a = pq.top();
			pq.pop();
			z -= a;
			ans++;
			if(a/2>0){
				pq.push(a/2);
			}
		}
		if(z>0){
			cout<<"Evacuate"<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}

	return 0;
}