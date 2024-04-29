//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* trimZeros(Node* head){
        if(head->data == 0){
            while(head->data == 0){
                head = head->next;
                if(head == NULL){
                    return new Node(0);
                }
            }
        }
        return head;
    }
    
    Node* reversell(Node* temp){
        Node* prev = NULL;
        while(temp!=NULL){
            Node* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        Node* temp1 = num1;
        Node* temp2 = num2;
        temp1 = reversell(temp1);
        temp2 = reversell(temp2);
        Node* dummy = new Node(-1);
        Node* tempo = dummy;
        int carry =0;
        
        while(temp1 != NULL || temp2 != NULL || carry){
            int sum=0;
            if(temp1){
                sum += temp1->data;
                temp1 = temp1->next;
            }
            if(temp2){
                sum += temp2->data;
                temp2 = temp2->next;
            }
            sum += carry;
            Node* newlist = new Node(sum % 10);
            carry = sum / 10;
            tempo->next = newlist;
            tempo = tempo->next;
        }
        
        dummy->next = reversell(dummy->next);
        dummy->next = trimZeros(dummy->next);

        return dummy->next;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends