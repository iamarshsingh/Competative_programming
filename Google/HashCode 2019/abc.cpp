     #include<bits/stdc++.h>
        #define ll long long 
        #define pb push_back 
        #define ins insert
        #define rs resize
        #define br break;
        #define cont continue;
        #define vi vector<int>
        #define vll vector<long long>
        #define si set<int>
        #define sll set<long long>
        #define pii pair<int,int>
        #define pll pair<long long, long long>
        #define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
        #define vec vector
        #define cend cout<<endl;
        #define sc second
        #define fr first
     
        using namespace std;
     
     
     
     
    bool comp(pair<set<string>,pair<int,int>> a,pair<set<string>,pair<int,int>> b)
    {
      return a.first.size()<b.first.size();
     
    }
     
    int ccol(set<string> a,set<string> b)
    {
      auto it=a.begin();
      int ret=0;
      while(it!=a.end())
      {
        if(b.find(*it)!=b.end())ret++;
        it++;
      }
     
      return min(ret,min((int)b.size()-ret,(int)a.size()-ret));
    }
     
    int main()
    {
       int n;
       cin>>n;
       vector<pair<set<string>,pair<int,int>>> q(n);
       
       for(int i=0;i<n;i++)
       {
          int n1;
          cin>>n1;
          int i1,i2;
          cin>>i1>>i2;
          q[i].sc={i1,i2};
     
          for(int j=0;j<n1;j++)
          {
            string s;
            cin>>s;
            q[i].fr.insert(s);
          }
       }
     
     
       sort(q.begin(),q.end(),comp);
     
     
       int i=0;
       vector<pair<int,int>> ans;
       bool v[n]={0};
       while(i<n)
       {
        int l = i;
        int r = min((int)2000+i,n-1);
        i += (int)2000+1;
        int c=r-l+1;
        int j=l;
        while(c!=0)
        {
          c--;
          v[j]=1;
          int cmax=-1;
          int in =-1;
          ans.pb(q[j].sc);
          if(c==0)break;
          for(int k=l;k<=r;k++)
          if(!v[k]){
            int col = ccol(q[j].fr,q[k].fr);
            if(col>cmax)cmax=col,in=k;
          }
          v[in]=1;
          j=in;
        }
       }
       cout<<ans.size()<<endl;
       for(int i=0;i<ans.size();i++)
       {
        cout<<ans[i].fr<<" ";
        if(ans[i].sc!=-1)cout<<ans[i].sc;
        cout<<endl;
       }
     
     
    }