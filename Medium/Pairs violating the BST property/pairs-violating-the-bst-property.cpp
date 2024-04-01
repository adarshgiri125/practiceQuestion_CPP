//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
    
    int merge(vector<int> &v, int left, int mid, int right, vector<int> &v2) {
    int i = left;
    int j = mid;
    int k = left;
    int inversions = 0;

    while (i < mid && j <= right) {
        if (v[i] <= v[j]) {
            v2[k++] = v[i++];
        } else {
            v2[k++] = v[j++];
            inversions += mid - i; 
        }
    }

    while (i < mid) {
        v2[k++] = v[i++];
    }

    while (j <= right) {
        v2[k++] = v[j++];
    }

    for (i = left; i <= right; i++) {
        v[i] = v2[i];
    }

    return inversions;
}

int count(vector<int> &v, int left, int right, vector<int> &v2) {
    int inversions = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        inversions += count(v, left, mid, v2);
        inversions += count(v, mid + 1, right, v2);
        inversions += merge(v, left, mid + 1, right, v2);
    }
    return inversions;
}

void inorderTraversal(Node *root, vector<int> &v) {
    if (root == nullptr) return;
    inorderTraversal(root->left, v);
    v.push_back(root->data);
    inorderTraversal(root->right, v);
}

int pairsViolatingBST(int n, Node *root) {
    if (root == nullptr) return 0;

    vector<int> v;
    inorderTraversal(root, v);

    vector<int> v2(n);
    return count(v, 0, v.size() - 1, v2);
}

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends