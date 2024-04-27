//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    void merge(vector<int> &v, int s, int mid, int e){
        int len1 = mid - s + 1;
        int len2 = e - mid;
        
        int arr[len1];
        int arr2[len2];
        
        int j = s;
        for(int i = 0; i<len1; i++){
            arr[i] = v[j++];
        }
        j = mid + 1;
        for(int i = 0; i<len2; i++){
            arr2[i] = v[j++];
        }
        
        int i = 0;
        j = 0;
        int k = s;
        
        while(i < len1 && j < len2){
            if(arr[i] < arr2[j]){
                v[k] = arr[i];
                i++;
            }
            else{
                v[k] = arr2[j];
                j++;
            }
            k++;
        }
        
        while(i < len1){
            v[k] = arr[i];
            i++;
            k++;
        }
        
        while(j < len2){
            v[k] = arr2[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int> &v, int s, int e){
        if(s >= e){
            return;
        }
        int mid = (s + e) / 2;
        mergeSort(v,s,mid);
        mergeSort(v,mid + 1,e);
        merge(v,s,mid,e);
    }
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        vector<int> v;
        struct Node *root = head;
        struct Node *ans = head;
        while(head != NULL){
            v.push_back(head -> data);
            head = head -> next;
        }
        
        mergeSort(v,0,v.size() - 1);
        
        
        int i = 0;
        while(root != NULL){
            root -> data = v[i];
            i++;
            root = root -> next;
        }
        
        return ans; 
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends