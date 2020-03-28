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

	int n,b,a;
	cin>>n>>b>>a;
	int arr[n];
	int cura=a;
	for(int i=0;i<n;i++)cin>>arr[i];
	int i;
	for(i=1;i<=n;i++){
		if(cura==a){
			cura--;
		}
		else if(cura<a && cura>0){
			if(arr[i-1]==1 && b>0){
				b--;
				cura++;
			}
			else{
				cura--;
			}
		}
		else{
			if(arr[i-1]==1 && b>0){
				b--;
				cura++;
			}
			else{
				b--;
			}
		}
		//cout<<i<<" "<<cura<<" "<<b<<endl;
		if(b==0 && cura==0) break;
	}
	if(i>n)cout<<n<<endl;
	else cout<<i<<endl;
	return 0;
}