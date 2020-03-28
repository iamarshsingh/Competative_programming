#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
using namespace std;
 


int main()
{

    int t;
    cin>>t;
    int xx=0;
 
    while(t!=0)
    {
        xx++;
        t--;
        int n;
        cin>>n;
        string s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        string ans;
        bool x=0;
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=-1;
        }
        for(int i=0;i<500;i++)
        {
            set<char> q;
            for(int j=0;j<n;j++){
                if(arr[j]==-1){
                    //cout<<j<<": "<<s[j][i%s[j].size()]<<endl;
                    q.insert(s[j][i%s[j].size()]);
                }
            }

            if(q.size()==1)
            {
                if(*q.begin()=='S')
                    ans.push_back('R');
                if(*q.begin()=='R')
                    ans.push_back('P');
                if(*q.begin()=='P')
                    ans.push_back('S');
                x=1;
                //break;
            }
 
            if(q.size()==2)
            {
                auto it=q.begin();
                char x = *it;
                it++;
                char y = *it;
                if((x=='R' and y == 'S') || (x=='S' and y == 'R'))
                    ans.push_back('R');
                if((x=='R' and y == 'P') || (x=='P' and y == 'R'))
                    ans.push_back('P');
                if((x=='P' and y == 'S') || (x=='S' and y == 'P'))
                    ans.push_back('S');
 
            }
 
            if(q.size()==3)
                break;
    
            for(int j=0;j<n;j++){
                if(arr[j]==-1){
                    //cout<<ans[ans.length()-1]<<endl;
                    if(ans[ans.length()-1]=='P' && s[j][i%s[j].size()]=='R') arr[j]=1;
                    else if(ans[ans.length()-1]=='R' && s[j][i%s[j].size()]=='S') arr[j]=1;
                    else if(ans[ans.length()-1]=='S' && s[j][i%s[j].size()]=='P') arr[j]=1;
                }
            }
            
        }
 
        cout<<"Case #"<<xx<<':'<<" ";
        if(x) cout<<ans<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
 
 
        
    }
}