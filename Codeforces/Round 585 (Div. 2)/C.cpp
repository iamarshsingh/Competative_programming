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

	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	deque<int> ab,ba;
	vector<pair<int,int>> ans;
	for(int i=0;i<n;i++){
		if(a[i]=='a' && b[i]=='b'){
			ab.push_back(i);
		}
		if(a[i]=='b' && b[i]=='a'){
			ba.push_back(i);
		}
	}

	if((ab.size()+ba.size())%2==1){
		cout<<-1<<endl;
		return 0;
	}

	while(ab.size()>1){
		ans.push_back({ab[0], ab[1]});
		ab.pop_front();
		ab.pop_front();
	}

	while(ba.size()>1){
		ans.push_back({ba[0], ba[1]});
		ba.pop_front();
		ba.pop_front();
	}

	if(ab.size()==1 && ba.size()==1){
		ans.push_back({ab[0], ab[0]});
		ans.push_back({ab[0], ba[0]});
	}

	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
	}
	return 0;
}