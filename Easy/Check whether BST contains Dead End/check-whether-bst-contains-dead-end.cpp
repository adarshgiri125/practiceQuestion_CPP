//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    void inorder(Node* root, vector<Node*> &ds){
            if(root== nullptr){
                return;
            }
            inorder(root->left, ds);
            ds.push_back(root);
            inorder(root->right, ds);
        }
  public:
    bool isDeadEnd(Node *root)
    {

        vector<Node* > temp;
        inorder(root, temp);
        if(temp.size()==1){
           return false; 
        }
    
        
        for(int i=0;i<temp.size()-1;i++){
            Node* curr = temp[i];
            if(!curr->left && !curr->right ){
                if(i==0 && curr->data !=1){
                    continue;
                }
                else if(i==0 && curr->data ==1 && temp[i+1]->data == 2){
                    return true;
                }
                else if(i>0 && curr->data - temp[i-1]->data ==1 && temp[i+1]->data - curr->data==1){
                    return true;
                }
            }
        }
        return false;
        
    }

};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends