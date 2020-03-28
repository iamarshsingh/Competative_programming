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

	ll a,n,m,sum=0,prevans=0;
	cin>>n>>m;
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> pq2;
	vector<int> ans(n,0);
	for(int i=0;i<n;i++){
		cin>>a;
		sum+=a;
		if(sum<=m){
			ans[i] = prevans;
			pq.push(a);
		}
		else{
			while(sum>m && !pq.empty()){
				//cout<<pq.top()<<endl;
				sum = sum-pq.top();
				pq2.push(pq.top());
				pq.pop();
				prevans++;
				ans[i] = prevans;
			}
			pq.push(a);
			while(!pq.empty() && !pq2.empty() && pq2.top()<pq.top()){
				sum = sum+pq2.top()-pq.top();
				int t1 = pq.top(), t2 = pq2.top();
				pq.pop();
				pq2.pop();
				pq.push(t2);
				pq2.push(t1);
			}
			while(!pq2.empty() && sum+pq2.top()<=m){
				sum = sum+pq2.top();
				pq.push(pq2.top());
				pq2.pop();
				prevans--;		
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}	