#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct trie{
	vector<int> pos;
	map<char,trie*> mp;
};

void insert(string s, trie* root, int pos, int index){
	if(pos>=s.length()){
		root->pos.push_back(index);
		return ;
	}
	//cout<<pos<<" "<<curr.length()<<" "<<s<<endl;
	auto it = root->mp.find(s[pos]);
	//cout<<"hgg"<<endl;
	if(it==root->mp.end()){
		//cout<<"here"<<endl;
		trie* r = new trie;
		r->pos.clear();
		r->mp.clear();
		root->mp[s[pos]] = r;
	}
	//cout<<"g"<<endl;
	root->pos.push_back(index);
	insert(s, root->mp[s[pos]], pos+1, index);
}

bool find(trie* root, int l, int r, string s, int pos){
	//cout<<s<<" "<<pos<<" "<<root->pos.size()<<endl;
	if(pos>=s.length()){
		auto m = lower_bound(root->pos.begin(), root->pos.end(), l);
		//cout<<m<<endl;
		if(m==root->pos.end()) return false;
		if((*m)>r || (*m)<l){
			return false;
		}
		else return true;
	}
	
	auto it = root->mp.find(s[pos]);
	if(it==root->mp.end()){
		return false;
	}
	else{
		return find(root->mp[s[pos]], l, r, s, pos+1);
	}
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	struct trie* root = new trie;
	root->pos.clear();
	root->mp.clear();
	string s,curr;
	vector<string> arr;
	cin>>s;
	//cout<<"gh"<<endl;
	insert(s, root, 0, 1);
	//cout<<curr<<"\n";
	arr.push_back(s);
	int q;
	cin>>q;
	int c,l,r,index=2;
	while(q--){
		cin>>c>>l>>r;
		if(c==1){
			cin>>s;
			curr = arr[r-1].substr(0, l-1) + s;
			//cout<<curr<<endl;
			arr.push_back(curr);
			insert(curr, root, 0, index);
			index++;
		}
		else if(c==2){
			curr = arr[r-1].substr(0, l);
			arr.push_back(curr);
			insert(curr, root, 0, index);
			index++;
		}
		else{
			// for(int i=0;i<arr.size(); i++){
			// 	cout<<arr[i]<<" ";
			// }
			// cout<<endl;
			cin>>s;
			if(find(root, l, r, s, 0)) cout<<"yes"<<"\n";
			else cout<<"no"<<"\n";
		}
	}

	return 0;
}