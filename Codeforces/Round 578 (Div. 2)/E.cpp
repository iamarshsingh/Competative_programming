#include<bits/stdc++.h>
using namespace std;
 
vector<int> lps(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

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
	string ans = "",s;
	for(int i=0;i<n;i++){
		cin>>s;
		string text = s;
		text += "$";
		for(int j=max(0, (int)(ans.length()-s.length())); j<ans.length(); j++){
			text += ans[j];
		}

		vector<int> pi = lps(text);
		for(int j=pi.back(); j<s.length(); j++){
			ans += s[j];
		}
	}
	cout<<ans<<endl;
}