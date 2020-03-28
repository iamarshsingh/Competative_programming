#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n;
        int visited[n];
        list<int> arr[n];

        for(int i=0;i<n;i++){
            arr[i].clear();
            visited[i]=0;
        }

        for(int i=1;i<n;i++){
            cin>>a>>b;
            arr[a-1].push_back(b-1);
            arr[b-1].push_back(a-1);
        }
        list<int> que;
        list<int>::iterator i;
        que.push_back(0);
        visited[0]=1;
        int temp=0,c=2;
        int l=1,r=0;

        while(!que.empty()){
            temp = que.front();
            que.pop_front();

            if(visited[temp]==2)c=1;
            else c=2;

            for (i = arr[temp].begin(); i != arr[temp].end(); ++i)
            {
                //cout<<visited[*i]<<endl;
                if (visited[*i]==0)
                {
                    visited[*i] = c;
                    que.push_back(*i);
                    if(c==2)r++;
                    else l++;
                }
            }
        }
        //cout<<l<<" "<<r<<endl;

        if(l==r){
            cout<<1<<endl;
            for(int i=0;i<n;i++){
                if(visited[i]==1){
                    cout<<i+1<<" ";
                }
            }
            cout<<endl;
            for(int i=0;i<n;i++){
                if(visited[i]==2){
                    cout<<i+1<<" ";
                }
            }
            cout<<endl;
        }
        else{
            /*
            for(int i=0;i<n;i++){
                cout<<"check: "<<i+1<<" "<<visited[i]<<" "<<arr[i].size()<<endl;
            }
            */
            if(l<r){
                for(int i=0;i<n;i++){
                    if(visited[i]==2 && arr[i].size()==1){
                        visited[i]=1;
                        l++;
                        r--;
                    }
                    if(l==r)break;
                }
            }
            else{
                //cout<<"je"<<endl;
                for(int i=0;i<n;i++){
                    if(visited[i]==1 && arr[i].size()==1){
                        visited[i]=2;
                        //cout<<visited[i]<<endl;
                        l--;
                        r++;
                    }
                    if(l==r)break;
                }
            }
            /*
            for(int i=0;i<n;i++){
                cout<<"check: "<<i+1<<" "<<visited[i]<<" "<<arr[i].size()<<endl;
            }
            */
            cout<<2<<endl;
            for(int i=0;i<n;i++){
                if(visited[i]==1){
                    cout<<i+1<<" ";
                }
            }
            cout<<endl;
            for(int i=0;i<n;i++){
                if(visited[i]==2){
                    cout<<i+1<<" ";
                }
            }
            cout<<endl;
        }
    }
}
