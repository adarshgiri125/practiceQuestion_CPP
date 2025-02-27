//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<pair<int,int>>st;
    int ele=INT_MAX;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        ele=min(ele,x);
        st.push({x,ele});
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!st.empty())
        st.pop();
        if(!st.empty())
        {
            ele=st.top().second;
        }
        else
        {
            ele=INT_MAX;
        }
    }

    // Returns top element of the Stack
    int peek() {
        if(!st.empty())
        return st.top().first;
        else
        return -1;
        // code here
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(!st.empty())
        return st.top().second;
        else
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends