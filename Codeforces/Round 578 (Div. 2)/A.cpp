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
	char c;
	int arr[10] = {0};
	for(int i=0;i<n;i++){
		cin>>c;
		if(c=='L'){
			for(int j=0;j<10;j++){
				if(arr[j]==0){
					arr[j]=1;
					break;
				}
			}
		}
		else if(c=='R'){
			for(int j=9;j>=0;j--){
				if(arr[j]==0){
					arr[j]=1;
					break;
				}
			}
		}
		else{
			arr[c-'0']=0;
		}
	}
	for(int j=0;j<10;j++)
		cout<<arr[j];
	cout<<endl;
	return 0;
}