#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n,m;
	cin>>n;
	string a;
	deque<deque<int>> s(n);
	for(int i=0;i<n;i++){
		cin>>a;
		for(int j=0;j<a.length();j++){
			//cout<<"here"<<endl;
			s[i].push_back(a[j]-'0');
		}
	}
	m=a.length();
	int prev=0;
	int cc=0;
	while(true){
		cc++;
		int emp=0;
		deque<int> freq[10];
		for(int i=0;i<n;i++){
			if(s[i].size()>0){
				freq[s[i].front()].push_back(i);
			}
			else{
				emp++;
			}
		}
		bool pos=false;
		for(int i=0;i<10;i++){
			//cout<<"freq[i]: "<<freq[i].size()<<endl;
			if(freq[i].size()>0)pos=true;
		}
		if(!pos){
			//cout<<"exit"<<endl;
			break;
		}

		int done=0;
		int ulim=prev+1,llim=0;
		for(int i=prev;i<ulim && i>=llim;){
			//cout<<"here"<<endl;
			while(!freq[i].empty()){
				//cout<<freq[i].size()<<endl;
				//cout<<"here"<<endl;
				done++;
				cout<<freq[i].front()+1<<" ";
				s[freq[i].front()].pop_front();
				while(!s[freq[i].front()].empty() && s[freq[i].front()].front()==i){
					done++;
					cout<<freq[i].front()+1<<" ";
					s[freq[i].front()].pop_front();
				}
				if(!s[freq[i].front()].empty()){
					freq[s[freq[i].front()].front()].push_back(freq[i].front());
				}
				freq[i].pop_front();
			}
			prev=i;
			if(cc%2==0 && (emp==n || freq[i+1].size()>0 || done<(n/2)) && ulim<10){
				ulim++;
				i++;
			}
			else if(cc%2==1 && (emp==n || freq[i-1].size()>0 || done<(n/2))){
				ulim--;
				i--;
			}
			else{
				if(i<9 && freq[i+1].size()>0){
					ulim++;
					i++;
				}
				if(i>0 && freq[i-1].size()>0){
					ulim--;
					i--;
				}
				break;
			}
			if(i<0 || i>=10)break;
		}
		//cout<<"emp: "<<emp<<endl;
	}

	return 0;
}