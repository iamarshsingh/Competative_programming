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
	double a;
	int arr[n];
	bool poss[n]={false};
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a;
		arr[i] = floor(a);
		if(a>(double)arr[i]) poss[i]=true;
		//cout<<arr[i]<<endl;
		sum += arr[i];
	}
	int i=0;
	while(sum<0){
		if(poss[i]){
			arr[i]++;
			sum++;
		}
		i++;
	}
	for(int i=0;i<n;i++) cout<<arr[i]<<endl;
	return 0;
}