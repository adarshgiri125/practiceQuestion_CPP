//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 0);
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> s;
        // Find the previous less element for each element
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                left[i] = s.top();
            }
            s.push(i);
        }
        // Clear the stack to reuse it
        while (!s.empty()) s.pop();
        // Find the next less element for each element
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                right[i] = s.top();
            }
            s.push(i);
        }
        // Fill the result array
        for (int i = 0; i < n; ++i) {
            int window_size = right[i] - left[i] - 1; // Calculate the size of the window
            result[window_size - 1] = max(result[window_size - 1], arr[i]); // Update the result
        }
        // Fill in the maximums for smaller window sizes
        for (int i = n - 2; i >= 0; --i) {
            result[i] = max(result[i], result[i + 1]);
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends