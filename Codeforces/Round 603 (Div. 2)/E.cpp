#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

signed main(){
    fastio

    int n;
    cin>>n;
    string s;
    cin>>s;

    vector<int> l(N,0);
    vector<int> r(N,0);
    vector<int> lmin(N,0);
    vector<int> rmin(N,0);
    vector<int> lmax(N,0);
    vector<int> rmax(N,0);
    string curr = string(N,' ');
    //cout<<curr.length()<<"\n";
    int pos=1;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            if(curr[pos]=='(') l[pos]--;
            if(curr[pos]==')') l[pos]++;
            curr[pos]='(';
            l[pos]++;
        }
        else if(s[i]==')'){
            if(curr[pos]=='(') l[pos]--;
            if(curr[pos]==')') l[pos]++;
            curr[pos] = ')';
            l[pos]--;
        }
        else if(s[i]=='L'){
            if(pos!=1){
                r[pos] = r[pos+1];
                if(curr[pos]=='(') r[pos]--;
                if(curr[pos]==')') r[pos]++;
                rmin[pos] = min(rmin[pos+1], r[pos]);
                rmax[pos] = max(rmax[pos+1], r[pos]);
                pos--;
                //r[pos] = r[pos+1];
            }
        }
        else if(s[i]=='R'){
            pos++;
            l[pos] = l[pos-1];
            if(curr[pos]=='(') l[pos]++;
            if(curr[pos]==')') l[pos]--;
        }
        else{
            if(curr[pos]=='(') l[pos]--;
            if(curr[pos]==')') l[pos]++;
            curr[pos] = s[i];
        }
        lmin[pos] = min(lmin[pos-1], l[pos]);
        lmax[pos] = max(lmax[pos-1], l[pos]);
        //rmin[pos+1] = min(rmin[pos+2], r[pos+1]);
        //rmax[pos+1] = max(rmax[pos+2], r[pos+1]);
        if( ( lmin[pos]==0 && rmin[pos+1]==0 ) && l[pos]==r[pos+1]){
            //cout<<curr<<"\n";
            cout<<max(lmax[pos], rmax[pos+1])<<" ";
        }
        else{
            //cout<<curr<<"\n";
            cout<<"-1 ";
        }
    }
    cout<<"\n";
}

// (()(()())())(()) 