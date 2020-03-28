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
	
	int arr[4];
	for(int i=0;i<4;i++)cin>>arr[i];
	sort(arr,arr+4);

	int a,b,c,temp;
	temp = arr[1]-arr[0];
	if(temp==0){
		c = arr[2]/2;
		b = c;
	}
	else{
		c = (temp+arr[2])/2;
		b = arr[2]-c;
	}
	a = arr[1]-c;
	cout<<a<<" "<<b<<" "<<c<<" "<<endl;
	return 0;
}