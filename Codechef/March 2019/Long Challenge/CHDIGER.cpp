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
		string n;
		char d;
		cin>>n>>d;
		char small[n.size()];
		small[n.size()-1]=n[n.size()-1];
		for(int i=n.size()-2;i>=0;i--){
			small[i] = min(n[i],small[i+1]);
		}
		//cout<<n<<endl;
		//cout<<d<<endl;
		int rep=0;
		string left="";
		for(int i=0;i<n.size();i++){
			if(n[i]>small[i] || n[i]>=d){
				rep++;
			}
			else{
				left = left + char(n[i]);
			}
			//cout<<left<<endl;
		}
		//cout<<endl;
		//cout<<left<<endl;
		left = left + string(rep,d);
		cout<<left<<endl;
	}

	return 0;
}