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
	string s;
	cin>>s;
	if(n%2==1){
		cout<<"No"<<endl;	
	}	
	else{
		int count=0,minn=0,l=0,r=0;
		for(int i=0;i<n;i++){
			if(s[i]=='('){
				count++;
				l++;
			}
			else{
				count--;
				r++;
			}
			minn = min(count, minn);
		}
		//cout<<minn<<endl;
		if(minn>=-1 && l==r)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

	return 0;
}