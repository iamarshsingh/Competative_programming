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
		int a,b;
		cin>>a>>b;
		string s;
		cin>>s;
		priority_queue<int> pq;
		int curr=0;
		for(int i=0;i<s.length(); i++){
			if(s[i]=='.'){
				curr++;
			}
			else{
				if(curr>=min(a,b)) pq.push(curr);
				curr=0;
			}
		}
		if(curr>=min(a,b)) pq.push(curr);
		int turn = 1;
		while(!pq.empty()){
			curr = pq.top();
			pq.pop();
			if(pq.empty()){
				if(curr==1) curr = (curr - a);
				else curr = (curr - b);
				pq.push(ceil(curr/2.0));
				pq.push((curr/2));
			}
			else{
				if(curr==1) pq.push(curr-a);
				else pq.push(curr-b);
			}
			curr = (curr+1)%2;
		}
		if(curr%2==0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}

	return 0;
}