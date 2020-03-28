#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

string lcs(string a, string b){

	int L[a.length()+1][b.length()+1];
	for(int i=0;i<=a.length();i++){
		for(int j=0;j<=b.length();j++){
			if(i==0 || j==0){
				L[i][j]=0;
			}
			else if(a[i-1]==b[j-1]){
				L[i][j]=L[i-1][j-1]+1;
			}
			else{
				L[i][j] = max(L[i][j-1], L[i-1][j]);
			}
		}
	}

	int len=L[a.length()][b.length()];

	string ans = string(len,'0');
	
	int i=a.length(),j=b.length();
	while(i>0 && j>0){
		if(a[i-1]==b[j-1]){
			ans[--len] = a[i-1];
			i--;j--;
		}
		else if(L[i-1][j] > L[i][j-1]){
			i--;
		}
		else j--;
	}

	return ans;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	string s,t;
	cin>>s>>t;
	cout<<lcs(s,t)<<endl;

	return 0;
}