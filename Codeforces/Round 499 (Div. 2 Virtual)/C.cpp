#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(12)<<fixed;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,m;
	cin>>n>>m;
	double takeof[n];
	double land[n];
	for(int i=0;i<n;i++) cin>>takeof[i];
	for(int i=0;i<n;i++) cin>>land[i];
	for(int i=0;i<n;i++){
		if(takeof[i]==1 || land[i]==1){
			cout<<-1<<endl;
			return 0;
		}
	}
	double curr=m;
	//cout<<curr<<" "<<((land[0]-1))<<endl;
	double fuel = (curr/(land[0]-1));
	curr += (curr/(land[0]-1));
	int i=n-1;
	//cout<<curr<<" "<<fuel<<endl;
	while(i>0){
		fuel += (curr/(takeof[i]-1));
		curr += (curr/(takeof[i]-1));
		fuel += (curr/(land[i]-1));
		curr += (curr/(land[i]-1));
		i--;
		//cout<<curr<<" "<<fuel<<endl;
	}
	fuel += (curr/(takeof[0]-1));
	curr += (curr/(takeof[0]-1));
	//cout<<curr<<" "<<fuel<<endl;
	cout<<fuel<<endl;
	return 0;
}