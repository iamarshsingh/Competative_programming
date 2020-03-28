#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll ans=0;
ll n,t;


void solve(int sum, deque<int> g1, deque<int> g2, deque<int> g3, int g){
	if(sum==t) ans++;
	if(sum>t) return;
	if(g==1){
		for(int i=0;i<g2.size();i++){
			int temp = g2[g2.size()-1];
			g2.pop_back();
			solve(sum+temp,g1,g2,g3,1);
			g2.push_front(temp);
		}
		for(int i=0;i<g3.size();i++){
			int temp = g3[g3.size()-1];
			g3.pop_back();
			solve(sum+temp,g1,g2,g3,1);
			g3.push_front(temp);
		}
	}
	if(g==2){
		for(int i=0;i<g1.size();i++){
			int temp = g1[g1.size()-1];
			g1.pop_back();
			solve(sum+temp,g1,g2,g3,2);
			g1.push_front(temp);
		}
		for(int i=0;i<g3.size();i++){
			int temp = g3[g3.size()-1];
			g3.pop_back();
			solve(sum+temp,g1,g2,g3,2);
			g3.push_front(temp);
		}
	}
	if(g==3){
		for(int i=0;i<g1.size();i++){
			int temp = g1[g1.size()-1];
			g1.pop_back();
			solve(sum+temp,g1,g2,g3,3);
			g1.push_front(temp);
		}
		for(int i=0;i<g2.size();i++){
			int temp = g2[g2.size()-1];
			g2.pop_back();
			solve(sum+temp,g1,g2,g3,3);
			g2.push_front(temp);
		}
	}
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int a,b;
	cin>>n>>t;
	deque<int> g1,g2,g3;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(b==1){
			g1.push_back(a);
		}
		else if(b==2){
			g2.push_back(a);
		}
		else if(b==3){
			g3.push_back(a);
		}
	}
	for(int i=0;i<g1.size();i++){
		int temp = g1[g1.size()-1];
		g1.pop_back();
		solve(temp,g1,g2,g3,1);
		g1.push_front(temp);
	}
	for(int i=0;i<g2.size();i++){
		int temp = g2[g2.size()-1];
		g2.pop_back();
		solve(temp,g1,g2,g3,2);
		g2.push_front(temp);
	}
	for(int i=0;i<g3.size();i++){
		int temp = g3[g3.size()-1];
		g3.pop_back();
		solve(temp,g1,g2,g3,3);
		g3.push_front(temp);
	}

	cout<<ans<<endl;

	return 0;
}