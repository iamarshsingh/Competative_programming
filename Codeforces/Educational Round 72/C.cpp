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

	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		int n = s.length();
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '0')
				continue;
			int val = 0;
			int zeroes = 0;
			for(int j = i - 1; j >= 0; j--)
			{
				if(s[j] == '0')
					zeroes++;
				else
					break;
			}
			for(int j = i; j < n; j++)
			{
				val = val * 2 + (s[j] - '0');
				if((j - i + 1 + zeroes) >= val)
					ans++;
				if(val > n)
					break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}