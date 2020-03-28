//Z Algorithm code reffered from GEEKSFORGEEKS

#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

string s;
ll cnt=0;
vector<pair<int,int>>::iterator itr;

struct comp{
    bool operator()(const pair<int,int> &a, const int & b)
    {
        return (a.first < b);
    }
    bool operator()(const int & a,const pair<int,int> &b)
    {
        return (a < b.first);
    }
};

bool poss(vector<int> seq, vector<pair<int,int>> positions[],int start){
	int filed=-1;
	for(int t=start;t<seq.size();t++){
		bool pos=false;
		int i = seq[t];
		itr = lower_bound(positions[i].begin(), positions[i].end(),filed+1,comp());
		if(itr!=positions[i].end() && (*itr).second>filed){
			pos=true;
			//cout<<(*itr).second<<" "<<filed<<endl;
			filed = (*itr).second;
		}
		/*for(int j=0; j<positions[i].size();j++){
			if(positions[i][j].first>filed){
				filed = positions[i][j].second;
				pos=true;
			}
			if(pos)break;
		}*/
		if(!pos)return false;
	}
	return true;
}

void posspair(vector<int> seq1, vector<int> seq2, vector<pair<int,int>> positions[], int one, int two, int c, int filed){
	if(c==1 && one<seq1.size()){
		bool pos=false;
		int i = seq1[one];
		itr = lower_bound(positions[i].begin(), positions[i].end(),filed+1,comp());
		if(itr!=positions[i].end() && (*itr).second>filed){
			pos=true;
			//cout<<(*itr).second<<" "<<filed<<endl;
			filed = (*itr).second;
		}
		if(pos){
			//cout<<"enter: "<<one<<" "<<two<<endl;
			if(one==seq1.size()-1 && two==seq2.size()-1){
				cnt++;
				return;
				//cout<<"case: "<<one<<" "<<two<<endl;
			}
			//cout<<two<<endl;
			//cout<<((seq2.size()-1))<<endl;
			//cout<<"prep: "<<(two<(int)(seq2.size()-1))<<endl;
			if(one<(int)(seq1.size()-1)){
				//cout<<"enter2: "<<one<<" "<<two<<endl;
				posspair(seq1,seq2,positions,one+1,two,1,filed);
			}
			if(two<(int)(seq2.size()-1)){
				//cout<<"enter2: "<<one<<" "<<two<<endl;
				posspair(seq1,seq2,positions,one,two+1,2,filed);
			}
		}
		else return;
	}
	else if(c==2 && two<seq2.size()){
		bool pos=false;
		int i = seq2[two];
		itr = lower_bound(positions[i].begin(), positions[i].end(),filed+1,comp());
		if(itr!=positions[i].end() && (*itr).second>filed){
			pos=true;
			//cout<<(*itr).second<<" "<<filed<<endl;
			filed = (*itr).second;
		}
		if(pos){
			//cout<<"enter: "<<one<<" "<<two<<endl;
			if(one==seq1.size()-1 && two==seq2.size()-1){
				cnt++;
				//cout<<"case: "<<one<<" "<<two<<endl;
			}
			if(one<(int)(seq1.size()-1)){
				//cout<<"enter2: "<<one<<" "<<two<<endl;
				posspair(seq1,seq2,positions,one+1,two,1,filed);
			}
			if(two<(int)(seq2.size()-1)){
				//cout<<"enter2: "<<one<<" "<<two<<endl;
				posspair(seq1,seq2,positions,one,two+1,2,filed);
			}
		}
		else return;
	}
	else return;
}

void getZarr(string str, int Z[]) 
{ 
    int n = str.length(); 
    int L, R, k; 
  
    L = R = 0; 
    for (int i = 1; i < n; ++i) 
    { 
        if (i > R) 
        { 
            L = R = i; 
  
            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else
        { 
            k = i-L; 
  
            if (Z[k] < R-i+1) 
                Z[i] = Z[k]; 
  
            else
            { 
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
        } 
    } 
}


vector<pair<int,int>> search(string text, string pattern)
{
    string concat = pattern + "$" + text; 
    int l = concat.length(); 
  	vector<pair<int,int>> ans;
    int Z[l]; 
    getZarr(concat, Z); 
  
    for (int i = 0; i < l; ++i) 
    { 
        if (Z[i] == pattern.length())
        	ans.push_back(make_pair(i - pattern.length() -1, pattern.length() + i - pattern.length() -2));
    }

    return ans;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n,m;
	cin>>n>>m;
	cin>>s;
	string arr[m];
	for(int i=0;i<m;i++){
		cin>>arr[i];
	}

	vector<pair<int,int>> positions[m];
	for(int i=0;i<m;i++){
		positions[i] = search(s,arr[i]);
		/*
		for(int j=0;j<positions[i].size();j++){
			cout<<positions[i][j].first<<" "<<positions[i][j].second<<"\t";
		}
		cout<<endl;
		*/
	}
	/*
	vector<int> anagrama(m);
	vector<vector<int>> A;
	for(int i=0;i<(m);i++){
		anagrama[i]=i;
	}
	//sort(anagrama.begin(), anagrama.end());
	do {
	    A.push_back(anagrama);
	} while (next_permutation(anagrama.begin(), anagrama.end()));

	int nums=0;
	for(int i=0;i<A.size();i++){
		if(poss(A[i],positions,0)){
			nums++;
		}
	}
	cout<<nums<<endl;
	*/
	
	ll half = m/2;
	
	vector<int> anagrama(half);
	vector<vector<int>> A,B;
	for(int i=0;i<(m/2);i++){
		anagrama[i]=i;
	}
	sort(anagrama.begin(), anagrama.end());
	do {
	    if(poss(anagrama,positions,0))A.push_back(anagrama);
	} while (next_permutation(anagrama.begin(), anagrama.end()));
	
	if(half<((m)-half)) anagrama.push_back(0);
	for(int i=(m/2);i<m;i++){
		anagrama[i-(m/2)]=i;
	}
	sort(anagrama.begin(), anagrama.end());
	do {
	    if(poss(anagrama,positions,0))B.push_back(anagrama);
	} while (next_permutation(anagrama.begin(), anagrama.end()));

	int nums=0;
	for(int i=0;i<A.size();i++){
		for(int j=0;j<B.size();j++){
			//cout<<A[i][0]<<" "<<B[j][0]<<" "<<B[j][1]<<endl;
			posspair(A[i],B[j],positions,0,-1,1,-1);
			posspair(A[i],B[j],positions,-1,0,2,-1);
		}
	}
	cout<<cnt<<endl;
	/*
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[i].size();j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	/*
	for(int i=0;i<B.size();i++){
		for(int j=0;j<B[i].size();j++){
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	return 0;
}