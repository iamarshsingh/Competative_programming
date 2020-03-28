#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
	
	int arr[100];
	string curr="? ";
	for(int i=1;i<=100;i++){
		arr[i-1] = i;
		curr += to_string(i);
		curr += " ";
	}
	cout<<curr;
	fflush(stdout);
	int n;
	cin>>n;
	int freq[20000] = {0};
	curr = "? ";
	for(int i=0;i<100;i++){
		freq[arr[i]^n]++;
		arr[i] = arr[i]<<7;
		curr += to_string(arr[i]);
		curr += " ";
	}
	cout<<curr;
	fflush(stdout);
	cin>>n;
	for(int i=0;i<100;i++){
		//cout<<arr[i]<<endl;
		freq[arr[i]^n]++;
	}
	int ans=0,maxx=0;
	for(int i=0;i<20000;i++){
		if(freq[i]>maxx){
			ans = i;
			maxx = freq[i];
		}
	}
	curr = "! ";
	curr += to_string(ans);
	cout<<curr;
	fflush(stdout);
	return 0;
}