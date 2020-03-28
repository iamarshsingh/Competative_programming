#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string s;
	int h1,h2,m1,m2;
	scanf("%d:%d",&h1,&m1);
	scanf("%d:%d",&h2,&m2);
	int diff = (h2-h1)*60 + (m2-m1);
	diff = diff/2;
	h1 = h1 + (diff/60);
	m1 = m1 + (diff%60);
	h1 = h1 + (m1/60);
	m1 = m1%60;
	cout << setfill('0') << setw(2)<<h1<<":"<< setfill('0') << setw(2)<<m1<<endl;
	//cout<<setfill('0')<<setw(2)<<h1<<endl;
	//printf("%2d:%2d\n",h1,m1);
	return 0;
}