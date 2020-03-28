#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#define int long long int
#define ld cpp_dec_float_50
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;
using boost::multiprecision::cpp_dec_float_50; 


bool vowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        return true;
    }
    else{
        return false;
    }
}

ld power(ld a, int b){
    ld ans = 1.0;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans*a); 
        
        b = b>>1;
        a = (a*a);
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;

    if(n<=10){
        string s;
        vector<pair<ld,ld>> freqA(26, make_pair(0.0,0.0)), freqB(26, make_pair(0.0,0.0));
        int anum=0,bnum=0;
        for(int i=0;i<n;i++){
            cin>>s;
            map<int,int> m;
            bool a = true;
            for(int j=0;j<s.length();j++){
                m[s[j]-'a']++;
            }
            if(s.length()==2){
                if(vowel(s[0]) || vowel(s[1])){
                    a=true;
                }
                else a = false;
            }
            else{
                for(int j=0; j<(s.length()-2); j++){
                    if( (vowel(s[j]) && vowel(s[j+1])) || (vowel(s[j+1]) && vowel(s[j+2])) || (vowel(s[j]) && vowel(s[j+2])) ){
                        a = true;
                    }
                    else{
                        a=false;
                        break;
                    }
                }
            }
            if(a){
                anum++;
                for(pair<int,int> j: m){
                    freqA[j.first].first++;
                    freqA[j.first].second+=j.second;
                }
            }
            else{
                bnum++;
                for(pair<int,int> j: m){
                    freqB[j.first].first++;
                    freqB[j.first].second+=j.second;
                }
            }
        }
        ld ans1=1.0, ans2=1.0, ans3=1.0;
        for(int i=0;i<26;i++){
            //cout<<freqA[i].first<<" "<<freqA[i].second<<"\n";
            //cout<<freqB[i].first<<" "<<freqB[i].second<<"\n";
            if(freqA[i].second >= 1.00){
                ans1 *= (freqA[i].first);
                ans2 *= ( 1 / freqA[i].second );
            }
            if(freqB[i].second >= 1.00){
                ans1 *= ( 1.0 / freqB[i].first );
                ans2 *= ( freqB[i].second );
            }
        }
        int p = min(anum, bnum);
        if(anum>p){
            for(int i=0; i<26; i++){
                if(freqA[i].second >= 1.00){
                    ans3 *= ( 1.0 / freqA[i].second );
                }
            }
        }
        else if(bnum>p){
            for(int i=0; i<26; i++){
                if(freqB[i].second >= 1.00){
                    ans3 *= ( freqB[i].second );
                }
            }
        }
        //cout<<ans1<<" "<<ans2<<" "<<p<<" "<<power(ans3, max(anum, bnum)-p)<<'\n';
        ld ans = (ans1*power(ans2,p)*power(ans3, max(anum, bnum)-p));
        if(ans>=10000000.0){
            cout<<"Infinity"<<"\n";
        }
        else{
            cout<<ans<<"\n";
        }
        return;
    }

    string s;
    vector<pair<ld,ld>> freqA(26, make_pair(0.0,0.0)), freqB(26, make_pair(0.0,0.0));
    int anum=0,bnum=0;
    for(int i=0;i<n;i++){
        cin>>s;
        map<int,int> m;
        bool a = true;
        for(int j=0;j<s.length();j++){
            m[s[j]-'a']++;
        }
        if(s.length()==2){
            if(vowel(s[0]) || vowel(s[1])){
                a=true;
            }
            else a = false;
        }
        else{
            for(int j=0; j<(s.length()-2); j++){
                if( (vowel(s[j]) && vowel(s[j+1])) || (vowel(s[j+1]) && vowel(s[j+2])) || (vowel(s[j]) && vowel(s[j+2])) ){
                    a = true;
                }
                else{
                    a=false;
                    break;
                }
            }
        }
        if(a){
            anum++;
            for(pair<int,int> j: m){
                freqA[j.first].first++;
                freqA[j.first].second+=j.second;
            }
        }
        else{
            bnum++;
            for(pair<int,int> j: m){
                freqB[j.first].first++;
                freqB[j.first].second+=j.second;
            }
        }
    }
    ld ans1=1.0, ans2=1.0, ans3=1.0;
    for(int i=0;i<26;i++){
        //cout<<freqA[i].first<<" "<<freqA[i].second<<"\n";
        //cout<<freqB[i].first<<" "<<freqB[i].second<<"\n";
        if(freqA[i].second >= 1.00){
            ans1 *= (freqA[i].first);
            ans2 *= ( 1.0 / freqA[i].second );
        }
        if(freqB[i].second >= 1.00){
            ans1 *= ( 1.0 / freqB[i].first );
            ans2 *= ( freqB[i].second );
        }
    }
    int p = min(anum, bnum);
    if(anum>p){
        for(int i=0; i<26; i++){
            if(freqA[i].second >= 1.00){
                ans3 *= ( 1.0 / freqA[i].second );
            }
        }
    }
    else if(bnum>p){
        for(int i=0; i<26; i++){
            if(freqB[i].second >= 1.00){
                ans3 *= ( freqB[i].second );
            }
        }
    }
    //cout<<ans1<<" "<<ans2<<" "<<p<<" "<<power(ans3, max(anum, bnum)-p)<<'\n';
    ld ans = ( ans1 * power(ans2,p) * power(ans3, max(anum, bnum)-p) );
    if(ans>=10000000.0){
        cout<<"Infinity"<<"\n";
    }
    else{
        cout<<ans<<"\n";
    }
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(12)<<fixed;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}   