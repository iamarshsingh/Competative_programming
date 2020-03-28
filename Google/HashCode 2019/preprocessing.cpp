#include <bits/stdc++.h>
using namespace std;

struct information{
	int id;
	int id2;
	int len;
	set<string> tags;
	information(){
		id2=-1;
	}
};

bool comp(information a, information b){
	return a.len > b.len;
}

vector<information> inp;
vector<information> ver;

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n,t;
	char orn;
	string tag;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>orn;
		cin>>t;
		information infos;
		infos.id = i;
		infos.len = t;
		for(int j=0;j<t;j++){
			cin>>tag;
			infos.tags.insert(tag);
		}
		
		if(orn=='H'){
			inp.push_back(infos);
		}
		else if(orn=='V'){
			ver.push_back(infos);
		}
	}

	//sort(ver.begin(),ver.end(), comp);
	//cout<<ver.size()<<endl;

	for(int i=0;i<ver.size()-1;i=i+2){
		for(auto j = ver[i+1].tags.begin(); j!=ver[i+1].tags.end(); j++){
			ver[i].tags.insert(*j);
		}
		ver[i].len = ver[i].tags.size();
		ver[i].id2 = ver[i+1].id;
		inp.push_back(ver[i]);
	}

	//sort(inp.begin(), inp.end(), comp);
	cout<<inp.size()<<endl;
	for(int i=0;i<inp.size();i++){
		cout<<inp[i].len<<" "<<inp[i].id<<" "<<inp[i].id2<<" ";
		for(auto j:inp[i].tags){
			cout<<j<<" ";
		}
		cout<<endl;
	}

	return 0;
}