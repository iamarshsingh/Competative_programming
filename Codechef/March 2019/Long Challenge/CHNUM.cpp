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
		int n,pos=0,neg=0;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]>0){
				pos++;
			}
			else{
				neg++;
			}
		}
		if(neg==0){
			cout<<pos<<" "<<pos<<endl;
		}
		else if(pos==0){
			cout<<neg<<" "<<neg<<endl;
		}
		else{
			if(pos>neg){
				cout<<pos<<" "<<neg<<endl;
			}
			else{
				cout<<neg<<" "<<pos<<endl;
			}
		}
	}
	return 0;
}