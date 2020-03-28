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

	int n,m,p;
	cin>>n>>m>>p;
	int A[n];
	int B[m];
	map<int,int> reqfreq;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for(int i=0;i<m;i++){
		cin>>B[i];
		reqfreq[B[i]]++;
	}
	sort(B,B+m);
	
	int curr = 0;
	map<int,int> curfreq;
	int done = 0;
	vector<int> ans;
	int diff = ((m-1)*p);
	int req = reqfreq.size();
	for(int i=0;i<p;i++){
		curfreq.clear();
		done=0;
		for(int j=i;j<n;j+=p){

			if(((j+1-i)/p) <= m){
				curfreq[A[j]]++;
				if(reqfreq.find(A[j])!=reqfreq.end()){
					if(curfreq[A[j]]==reqfreq[A[j]]){
						done++;
					}
				}
				//cout<<done<<" "<<"nums: "<<A[j]<<" "<<curfreq[A[j]]<<" "<<((j+p)/p)<<endl;
				if(((j+p)/p) == m){
					if(done==req){
						ans.push_back(i+1);
					}
				}
			}
			
			else{
				curfreq[A[j-diff-p]]--;
				if(reqfreq.find(A[j-diff-p])!=reqfreq.end()){
					if(curfreq[A[j-diff-p]]<reqfreq[A[j-diff-p]]){
						done--;
					}
				}
				//cout<<done<<" "<<A[j]<<" "<<curfreq[A[j]]<<endl;
				curfreq[A[j]]++;
				if(reqfreq.find(A[j])!=reqfreq.end()){
					//cout<<curfreq[A[j]]<<" "<<reqfreq[A[j]]<<endl;
					if(curfreq[A[j]]==reqfreq[A[j]]){
						done++;
					}
				}
				//cout<<done<<endl;
				if(done==req){
					ans.push_back(j-diff+1);
				}
			}
			//cout<<ans.size()<<endl;
		}
	}
	sort(ans.begin(), ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}