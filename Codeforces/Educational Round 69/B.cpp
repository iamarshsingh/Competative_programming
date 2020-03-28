#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void showlist(list <int> g) 
{ 
    list <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int n,a;
	cin>>n;
	int arr[n];
	int cent;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==n){
			cent = i;
		}
	}
	int i=cent-1, j=cent+1, curr=n-1;
	while(i>=0 || j<n){
		if(i>=0 && arr[i]==curr){
			curr--;
			i--;
		}
		else if(j<n && arr[j]==curr){
			curr--;
			j++;
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}