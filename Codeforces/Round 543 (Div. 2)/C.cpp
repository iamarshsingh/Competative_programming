#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n,k;
	cin>>n>>k;
	deque<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	deque<int> d;
	int curr=0;
	int per=0;
	double done=0;
	
	for(int i=0;i<k;i++){
		d.push_back(arr[i]);
	}
	sort(d.begin(), d.end());

	while(!arr.empty()){
		int temp = d.front();
		d.pop();
		curr++;
		while(!d.empty() && temp==d.front()){
			d.pop();
			curr++;
		}
		done+=curr;
		per = floor((double)done / n);
		sort(d.begin(), d.end());
		int limit = d[0] - temp;
		for(int j=0;j<d.size();j++){
			d[j] = d[j] - temp;
			
		}
	}
	return 0;
}