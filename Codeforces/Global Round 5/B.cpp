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
	int A[n];
	int B[n];
	for(int i=0;i<n;i++) cin>>A[i];
	for(int i=0;i<n;i++) cin>>B[i];

	int cross=0, pass=0, j=0;
	vector<bool> done(n+1, false);
	for(int i=0;i<n;i++){
		if(done[A[i]]==false){
			while(B[j]!=A[i]){
				j++;
				done[A[i]] = true;
			}
			cross = j+1 - cross - pass;
			pass++;
			done[A[i]] = true;
		}
	}
	cout<<cross<<endl;
	return 0;
}