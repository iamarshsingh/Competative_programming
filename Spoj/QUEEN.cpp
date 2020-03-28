#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		string s;
		cin>>n>>m;
		bool poss[n][m]={false};
		pair<int,int> start,end;
		for(int i=0;i<n;i++){
			cin>>s;
			for(int j=0;j<m;j++){
				if(s[j]=='S'){
					start.first = i;
					start.second = j;
					poss[i][j]=true;
				}
				else if(s[j]=='F'){
					end.first = i;
					end.second = j;
					poss[i][j]=false;
				}
				else if(s[j]=='.'){
					poss[i][j]=false;
				}
				else if(s[j]=='X'){
					poss[i][j]=true;
				}
			}
		}
		int dis[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				dis[i][j]=0;
			}
		}
		queue<pair<int,int>> q;
		q.push(start);
		int currdis = 1;
		cout<<t<<" : "<<endl;

		int saved=1;

		while(!q.empty()){
			cout<<"size: "<<q.size()<<endl;
			pair<int,int> curr = q.front();
			q.pop();
			saved--;
			int i,j;
			i=curr.first;
			j=curr.second+1;
			poss[i][j-1] = true;
			//cout<<i<<" "<<j-1<<endl;
			while(j<m){
				if(poss[i][j]==false){
					q.push(make_pair(i,j));
					//poss[i][j] = true;
					dis[i][j] = currdis;
				}
				else{
					break;
				}
				j++;
			}
			j=curr.second-1;
			while(j>=0){
				if(poss[i][j]==false){
					q.push(make_pair(i,j));
					//poss[i][j] = true;
					dis[i][j] = currdis;
				}
				else{
					break;
				}
				j--;
			}
			j=curr.second;
			i++;
			while(i<n){
				if(poss[i][j]==false){
					q.push(make_pair(i,j));
					//poss[i][j] = true;
					dis[i][j] = currdis;
				}
				else{
					break;
				}
				i++;
			}
			i=curr.first-1;
			while(i>=0){
				if(poss[i][j]==false){
					q.push(make_pair(i,j));
					//poss[i][j] = true;
					dis[i][j] = currdis;
				}
				else{
					break;
				}
				i--;
			}
			i=curr.first-1;j=curr.second+1;
			while(i>=0 && j<m){
				if(poss[i][j]==false){
					q.push(make_pair(i,j));
					//poss[i][j] = true;
					dis[i][j] = currdis;
				}
				else{
					break;
				}
				i--;
				j++;
			}
			i=curr.first+1;j=curr.second+1;
			while(i<n && j<m){
				if(poss[i][j]==false){
					q.push(make_pair(i,j));
					//poss[i][j] = true;
					dis[i][j] = currdis;
				}
				else{
					break;
				}
				i++;
				j++;
			}
			i=curr.first+1;j=curr.second-1;
			while(i<n && j>=0){
				if(poss[i][j]==false){
					q.push(make_pair(i,j));
					//poss[i][j] = true;
					dis[i][j] = currdis;
				}
				else{
					break;
				}
				i++;
				j--;
			}
			i=curr.first-1;j=curr.second-1;
			while(i>=0 && j>=0){
				if(poss[i][j]==false){
					q.push(make_pair(i,j));
					//poss[i][j] = true;
					dis[i][j] = currdis;
				}
				else{
					break;
				}
				i--;
				j--;
			}
			if(saved==0){
				currdis++;
				saved = q.size();
				cout<<"saved: "<<saved<<endl;
			}
		}

		if(dis[end.first][end.second]>0)
			cout<<dis[end.first][end.second]<<endl;
		else
			cout<<-1<<endl;
	}

	return 0;
}