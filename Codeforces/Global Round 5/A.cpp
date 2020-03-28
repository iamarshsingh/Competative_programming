#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	bool poss=false;
	while(n--){
		int x;
		cin>>x;
		if(x%2==0){
			cout<<(x/2)<<" ";
		}
		else{
			x = x >> 1;
			if(poss) x++;
			poss = !poss;
			cout<<x<<" ";
		}
	}
	
	return 0;
}