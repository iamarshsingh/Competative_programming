#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int a,n,m,k;
	cin>>n>>m>>k;
	pair<int,int> pow[n];
	for(int i=0;i<n;i++){
		cin>>pow[i].first;
		pow[i].second = i+1;
	}
	vector<pair<int,int>> schools[m+1];
	for(int i=0;i<n;i++){
		cin>>a;
		schools[a].push_back(pow[i]);
	}
	for(int i=1;i<=m;i++){
		sort(schools[i].begin(), schools[i].end(),[](pair<int,int> a, pair<int,int> b){
			return a.first>b.first;
		});
	}
	int need[k];
	for(int i=0;i<k;i++){
		cin>>need[i];
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<schools[i].size();j++){
			for(int l=0;l<k;l++){
				if(schools[i][j].second==need[l]){
					if(j>0)sum++;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}