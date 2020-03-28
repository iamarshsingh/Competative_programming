#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first) return a.second>b.second;
	else return a.first<b.first;
}

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
	ios_base::sync_with_stdio(false);
	vector<pair<int,pair<int,int>>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second.first;
		a[i].second.second=i+1;
	}
	sort(a.begin(),a.end());
	int i;
	int rmax = a[0].second.first;
	int prmax = a[0].first-1;
	for(i=1;i<a.size();i++){
		if(a[i].second.first<=rmax){
			cout<<a[i].second.second<<endl;return 0;
		}
		if(a[i].first <= prmax+1){
			// if(a[i])
			cout<<a[i-1].second.second<<endl; return 0;
			return 0;
		}
		if(a[i].first>rmax){
			prmax=a[i].first-1;
		}
		else prmax=rmax;
		rmax=a[i].second.first;
	}
	cout<<-1<<endl;

	return 0;
}