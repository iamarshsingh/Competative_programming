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
	string s;
	cin>>s;
	int lsum=0, rsum=0;
	int l=0,r=0;
	for(int i=0;i<(n/2);i++){
		if(s[i]=='?'){
			l++;
		}
		else{
			lsum += (s[i]-'0');
		}
	}
	for(int i=(n/2);i<n;i++){
		if(s[i]=='?'){
			r++;
		}
		else{
			rsum += (s[i]-'0');
		}
	}

	int i=1;
	while(l>0 || r>0){
		if(lsum>rsum){
			if(i%2==1){
				if(l>0){
					lsum += 9;
					l--;
				}
				else{
					if(rsum+(ceil(r/2.0)*9)>lsum){
						rsum += 9;
						r--;
					}
					else{
						r--;
					}
				}
			}
			else{
				if(r>0){
					rsum += min(9, lsum-rsum);
					r--;
				}
				else{
					cout<<"Monocarp"<<"\n";
					return 0;
				}
			}
		}
		else if(lsum==rsum){
			if(i%2==1){
				if(l>0){
					lsum += 9;
					l--;
				}
				else{
					rsum += 9;
					r--;
				}
			}
			else{
				if(r>0){
					r--;
				}
				else{
					l--;
				}
			}
		}
		else{
			if(i%2==1){
				if(r>0){
					rsum += 9;
					r--;
				}
				else{
					if(lsum+(ceil(l/2.0)*9)>rsum){
						lsum += 9;
						l--;
					}
					else{
						l--;
					}
				}
			}
			else{
				if(l>0){
					lsum += min(9, rsum-lsum);
					l--;
				}
				else{
					cout<<"Monocarp"<<"\n";
					return 0;
				}
			}
		}
		i++;
	}

	if(lsum==rsum) cout<<"Bicarp"<<"\n";
	else cout<<"Monocarp"<<"\n";

	return 0;
}