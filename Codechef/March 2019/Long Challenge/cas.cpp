#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<vector<int>> ans;
int a = 0;

void cas(int n, int pos, int val, vector<int> curr){
	curr.push_back(val);
	if(pos==n-1){
		ans.push_back(curr);
		a++;
		return;
	}
	//cout<<pos<<" "<<a<<endl;
	cas(n,pos+1,1,curr);
	cas(n,pos+1,2,curr);
} 

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	vector<int> curr;
	cas(15,0,1,curr);
	cas(15,0,2,curr);
	for(int i=0;i<ans.size();i++){
		cout<<15<<endl;
		for(int j=0;j<15;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}