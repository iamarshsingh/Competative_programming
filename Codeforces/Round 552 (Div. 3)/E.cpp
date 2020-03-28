#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

struct Node{
	int id;
	int data;
	Node* left;
	Node* right;
	Node(int i, int val){
		data = val;
		id=i;
		left = right = NULL;
	}
};

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n,k,a;
	cin>>n>>k;

	Node* arr[n];
	map<int,int,greater<int>> mp;
	for(int i=0;i<n;i++){
		cin>>a;
		arr[i] = new Node(i,a);
		mp[a]=i;
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	arr[0]->right=arr[1];
	arr[n-1]->left = arr[n-2];
	for(int i=1;i<n-1;i++){
		arr[i]->left = arr[i-1];
		arr[i]->right=arr[i+1];
	}
	int ans[n]={0};
	int here=0;
	map<int,int,greater<int>>::iterator itr;
	Node* itr2;
	Node* itr3;

	while(!mp.empty()){
		here++;
		if(here==3)here=1;
		itr = mp.begin();
		int curr = itr->second;
		//cout<<curr<<endl;
		Node* curnode = arr[curr];
		ans[curr]=here;
		int done=0;
		mp.erase(itr->first);
		for(itr2=curnode->left; itr2!=NULL && done<k; done++){
			mp.erase(itr2->data);
			//cout<<itr2->id<<endl;
			ans[itr2->id]=here;
			itr2=itr2->left;
		}
		done=0;
		for(itr3=curnode->right; itr3!=NULL & done<k;done++){
			mp.erase(itr3->data);
			//cout<<itr3->id<<endl;
			ans[itr3->id]=here;
			itr3=itr3->right;
		}
		if(itr2!=NULL) itr2->right = itr3;
		if(itr3!=NULL) itr3->left = itr2;
	}
	for(int i=0;i<n;i++)cout<<ans[i];
	cout<<endl;

	return 0;
}