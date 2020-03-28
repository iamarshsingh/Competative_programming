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
	if(n%2==0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		int tot=2*n;
		int arr[tot];
		int curr=1,ind=-1,don=0;
		while(don<tot){
			ind = (ind+1)%tot;
			arr[ind] = curr;
			curr++;
			ind = (ind+n)%tot;
			arr[ind] = curr;
			curr++;
			don += 2;
		}
		for(int i=0;i<tot;i++) cout<<arr[i]<<" ";
		cout<<endl;
	}

	return 0;
}