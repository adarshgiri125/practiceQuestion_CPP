//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>

/* a Node of the doubly linked list */
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends
/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if (head == nullptr) return nullptr;
        
        Node* ptr = head;
        Node* prv = nullptr;
        Node* nxt = nullptr;
        
        int pos = 1;
        
        // 1st position
        if (x == 1){
            nxt = head->next;
            nxt->prev = prv;
            
            delete head;
            return nxt;
        }
        
        while (ptr!=nullptr){
            if (ptr->next == nullptr && x == pos){
                prv = ptr->prev;
                prv->next = nxt;
                
                delete ptr;
                return head;
                
            }else if (x == pos){ // middle position
                prv = ptr->prev;
                nxt = ptr->next;
                
                prv->next = nxt;
                nxt->prev = prv;
                
                delete ptr;
                return head;
            }
            
            ptr = ptr->next;
            pos++;
        }
    }
};

//{ Driver Code Starts.

/* Function to print Nodes in a given doubly linked list
   This function is same as printList() of singly linked lsit */
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above functions*/
int main() {
    int t, x, n, i;
    scanf("%d", &t);

    while (t--) {
        /* Start with the empty list */
        struct Node *temp, *head = NULL;
        scanf("%d", &n);

        temp = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &x);

            if (head == NULL) {
                head = new Node(x);
                temp = head;
            } else {
                Node *temp1 = new Node(x);
                temp->next = temp1;
                temp1->prev = temp;
                temp = temp->next;
            }
        }

        scanf("%d", &x);

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        while (head->next != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }

        free(head);
    }
    return 0;
}

// } Driver Code Ends