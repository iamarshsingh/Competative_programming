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
		int n,q,k,l,r,c,p;
		cin>>n>>q>>k>>l>>r;
		vector<int> comes[q+1];
		vector<int> goes[q+1];
		for(int i=0;i<n;i++){
			cin>>c>>p;
			//cout<<c<<" "<<l<<" "<<r<<" "<<t<<endl;
			if(k>r){
				if(c<=l){
					//pairs[i].first.first = (l-c);
					if(l-c<=q)comes[l-c].push_back(p);
					if(r-c<=q)goes[r-c].push_back(p);
				}
				else if(c>l && c<=r){
					//pairs[i].first.first = 0;
					//pairs[i].first.second = (r-c);
					comes[0].push_back(p);
					if(r-c<=q)goes[r-c].push_back(p);
				}
				else{
					//pairs[i].first.first = 0;
					//pairs[i].first.second = 0;
				}
			}
			else if(k<=r && k>=l){
				if(c<=l){
					//pairs[i].first.first = (l-c);
					//pairs[i].first.second = q+1;
					if(l-c<=q)comes[l-c].push_back(p);
					//if(r-c<=q)goes[r-c].push_back(p);
				}
				else if(c>l && c<=r){
					//pairs[i].first.first = 0;
					//pairs[i].first.second = q+1;
					comes[0].push_back(p);
				}
				else{
					//pairs[i].first.first = (c-r);
					//pairs[i].first.second = q+1;
					if(c-r<=q)comes[c-r].push_back(p);
					//if(r-c<=q)goes[r-c].push_back(p);
				}
			}
			else{
				if(c<=l){
					//pairs[i].first.first = 0;
					//pairs[i].first.second = 0;
				}
				else if(c>l && c<=r){
					//pairs[i].first.first = 0;
					//pairs[i].first.second = (c-l);
					comes[0].push_back(p);
					if(c-l<=q)goes[c-l].push_back(p);
				}
				else{
					//pairs[i].first.first = (c-r);
					//pairs[i].first.second = (c-l);
					if(c-r<=q)comes[c-r].push_back(p);
					if(c-l<=q)goes[c-l].push_back(p);
				}
			}
		}
		//cout<<"here"<<endl;
		int ans[q+1];
		priority_queue<int, vector<int>, greater<int>> pq;
		map<int,int> mp;
		for(int i=0;i<=q;i++){
			//cout<<i<<" add: ";
			for(int j=0;j<comes[i].size();j++){
				if(mp[comes[i][j]]==0){
					pq.push(comes[i][j]);
				}
				mp[comes[i][j]]++;
				//cout<<comes[i][j]<<" ";
			}
			//cout<<endl<<"sub: ";
			for(int j=0;j<goes[i].size();j++){
				if(mp[goes[i][j]]==1){
					mp.erase(goes[i][j]);
				}
				else{
					mp[goes[i][j]]--;
				}
				//cout<<goes[i][j]<<" ";
			}
			//cout<<endl;
			if(!pq.empty()) ans[i] = pq.top();
			else ans[i] = -1;
			//cout<<"ee"<<endl;
			while(!pq.empty() && mp.find(pq.top())==mp.end()){
				//cout<<"er: "<<pq.top()<<endl;
				pq.pop();
			}
		}
		for(int i=1;i<=q;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}

	return 0;
}