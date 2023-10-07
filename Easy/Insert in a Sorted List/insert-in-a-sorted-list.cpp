//{ Driver Code Starts
//

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        if(head == NULL){
             Node* temp = new Node(data);
             return temp;
        }
        Node* prev = head;
        Node* curr = head -> next;
        if( data < prev -> data){
            Node* temp = new Node(data);
            temp -> next = prev;
            return temp;
        }
        
        while(curr != NULL){
            if(curr -> data > data && prev -> data <= data) {
                Node* temp = new Node(data);
                prev -> next = temp;
                temp -> next = curr;
                return head;
            }
            curr = curr -> next;
            prev = prev -> next;
        }
        Node* temp = new Node(data);
        prev -> next = temp;
        temp -> next = NULL;
        return head;
        
        
    }
};


//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends