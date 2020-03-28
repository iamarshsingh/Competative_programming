#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// C function to search a given key in a given BST
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;

    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

vector<int> Print(struct node *root, int k1, int k2, vector<int> ans)
{
   /* base case */
   if ( NULL == root )
      return ans;

   /* Since the desired o/p is sorted, recurse for left subtree first
      If root->key is greater than k1, then only we can get o/p keys
      in left subtree */
   if ( k1 < root->key )
     ans = Print(root->left, k1, k2, ans);

   /* if root's key lies in range, then prints root's key */
   if ( k1 <= root->key && k2 >= root->key )
        ans.push_back(root->key);

  /* If root->key is smaller than k2, then only we can get o/p keys
      in right subtree */
   if ( k2 > root->key )
     ans = Print(root->right, k1, k2, ans);

    return ans;
}

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main(){
    int n,q;
    cin>>n>>q;
    int ar[n+1][7001];
    struct node *roots [n+1];
    for(int i=0;i<n+1;i++){
        roots[i]=NULL;
        for(int j=0;j<7001;j++){
            ar[i][j]=0;
        }
    }
    //cout<<"h"<<endl;
    int ty,x,y,z,v;
    string ans="";
    while(q--){
        cin>>ty;
        if(ty==1){
            cin>>x>>v;
            roots[x] = NULL;
            roots[x] = insert(roots[x], v);
            ar[x][v]++;
        }
        else if(ty==2){
            cin>>x>>y>>z;
            vector<int> tttt;
            tttt.clear();
            tttt = Print(roots[y],1,7000,tttt);
            tttt = Print(roots[z],1,7000,tttt);
            roots[x] = NULL;

            for(int i=0;i<tttt.size();i++){
                struct node *ser = search(roots[x],tttt[i]);
                if(ser==NULL){
                    roots[x] = insert(roots[x],tttt[i]);
                    ar[x][tttt[i]]=1;
                }
                else{
                    ar[x][tttt[i]]++;
                }
            }
        }
        else if(ty==3){
            cin>>x>>y>>z;
            vector<int> t1,t2;
            t1.clear();
            t2.clear();
            t1 = Print(roots[y],1,7000,t1);
            t2 = Print(roots[z],1,7000,t2);
            roots[x] = NULL;
            for(int i=0;i<t1.size();i++){
                for(int j=0;j<t2.size();j++){
                    int gccdd = gcd(t1[i],t2[j]);
                    struct node *ser = search(roots[x],gccdd);
                    if(ser==NULL){
                        roots[x] = insert(roots[x],gccdd);
                        if(ar[y][t1[i]]%2==0){
                            ar[x][gccdd]=2;
                        }
                        else{
                            if(ar[z][t2[j]]%2==0)
                                ar[x][gccdd]=2;
                            else ar[x][gccdd]=1;
                        }

                    }
                    else{
                        if(ar[y][t1[i]]%2==0){
                            ar[x][gccdd]=ar[x][gccdd]+2;
                        }
                        else{
                            if(ar[z][t2[j]]%2==0)
                                ar[x][gccdd]+=2;
                            else ar[x][gccdd]+=1;
                        }
                    }
                }
            }
        }
        else if(ty==4){
            cin>>x>>v;
            //cout<<"hello"<<endl;
            if(ar[x][v]%2==0)ans = ans + string(1,'0');
            else{
                ans = ans + string(1,'1');
            }
            //cout<<"ans: "<<ans<<endl;
        }

        cout<<"====="<<endl;
        for(int i=1;i<=n;i++){
            vector<int> tt;
            tt.clear();
            tt = Print(roots[i],0,7001,tt);
            for(int j=0;j<tt.size();j++){
                cout<<tt[j]<<" ";
            }
            cout<<endl;
        }
        cout<<"ans: "<<ans<<endl;
        cout<<"====="<<endl;

    }
    cout<<ans<<endl;
    return 0;
}
