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

	int n,k;
	cin>>n>>k;
	if(n==2){
		if(k==0){
			cout<<1<<endl;
			cout<<"1 2"<<endl;
		}
		else{
			cout<<-1<<endl;
		}
		return 0;
	}
	if(k>(((n-1)*(n-2)) / 2)){
		cout<<-1<<endl;
		return 0;
	}
	vector<pair<int,int>> ans;
	ans.push_back({1,2});
	//ans.push_back({2,3});
	int curr=0,done = 2;
	int at2 = 1;
	int left = k;
	int leftnums = (n-2);
	for(int i=3;i<=n;i++){
		curr = at2;
		at2++;
		leftnums--;
		ans.push_back({2,i});
		int j=1;
		while(curr>(left-leftnums) && j<i){
			if(j==2){
				j++;
				continue;
			}
			ans.push_back({j,i});
			curr--;
			j++;
		}
		left = left - curr;
		//cout<<curr<<" "<<left<<endl;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}