#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string temp;
        cin>>temp;
        int len = temp.length();
        int chs[26];
        int nums=0;
        for(int i=0;i<26;i++)chs[i]=0;
        for(int i=0;i<len;i++)chs[temp[i]-'a']++;
        for(int i=0;i<26;i++){
            if(chs[i]>0){
                nums++;
            }
        }
        if(nums<=1){
            cout<<-1<<endl;
        }
        else{
            string ans;
            for(int i=0;i<26;i++){
                cout<<string(chs[i],'a'+i);
            }
            cout<<endl;
        }
    }

    return 0;
}
