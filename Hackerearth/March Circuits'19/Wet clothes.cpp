#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

deque<set<int>> rem(100);

bool comp(set<int> a, set<int> b){
	return a.size()>b.size();
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //*
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	//*/
	int n,m,g;
	cin>>n>>m>>g;
	int times[n];
	int dry[m];
	for(int i=0;i<n;i++)cin>>times[i];
	for(int j=0;j<m;j++)cin>>dry[j];
	bool stat[m]={false};
	set<int>::iterator itr;
	//cout<<"here"<<endl;
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(dry[j]<=(times[i]-times[i-1])){
				rem[i-1].insert(j);
			}
		}
	}
	int ans=0;
	//cout<<"here"<<endl;
	for(int i=0;i<g;i++){
		sort(rem.begin(), rem.end(), comp);
		set<int> curr(rem[0]);
		rem.pop_front();
		if(curr.size()==0) break;
		ans += curr.size();
		//cout<<"here: "<<ans<<endl;
		for (itr = curr.begin(); itr != curr.end(); ++itr){ 
	        stat[*itr] = true;
	    }

	    for(int j=0;j<rem.size();j++){
	    	for (itr = rem[j].begin(); itr != rem[j].end(); ++itr) 
		    {
		        if(stat[*itr]==true){
		        	rem[j].erase(*itr);
		        }
		    }
	    }	
	}
	cout<<ans<<endl;
	return 0;
}