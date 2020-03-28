#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int n;

bool check(vector<int> afreq, vector<int> bfreq, vector<int> num, int pos, int c){
	//cout<<"here"<<endl;
	if(pos==num.size()) return true;
	for(int i=0;i<10;i++){
		//cout<<"i: "<<i<<endl;
		if(afreq[i]>0){
			//cout<<"i: "<<i<<endl;
			int temp = num[n-pos-1];
			//cout<<"temp: "<<temp<<endl;
			if(i+c<=temp && bfreq[temp-i-c]>0){
				afreq[i]--;
				bfreq[temp-i-c]--;
				if(check(afreq,bfreq,num,pos+1,0)) return true;
				afreq[i]++;
				bfreq[temp-i-c]++;
			}
			if(i+c>temp && bfreq[(10+temp-i-c)%10]>0){
				afreq[i]--;
				bfreq[(10+temp-i-c)%10]--;
				if(check(afreq,bfreq,num,pos+1,1)) return true;
				afreq[i]++;
				bfreq[(10+temp-i-c)%10]++;	
			}
		}
	}
	return false;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		string a,b,c;
		cin>>n>>a>>b>>c;
		vector<int> num(c.length());
		vector<int> afreq(10,0);
		vector<int> bfreq(10,0);
		
		int i;
		for(i=0;i<a.length();i++){
			afreq[a[i]-'0']++;
		}
		afreq[0] += (n-i);
		for(i=0;i<b.length();i++){
			bfreq[b[i]-'0']++;
		}
		bfreq[0] += (n-i);
		for(i=0;i<c.length();i++){
			num[i] = c[i]-'0';
		}
		
		if(check(afreq,bfreq,num,0,0))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
	}

	return 0;
}