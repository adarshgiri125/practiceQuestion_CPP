//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int fun(vector<int>& arr, int low, int high, int key) 
    {
    
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
    
            if (arr[mid] == key) 
            {
                return mid;
            }
            // Check left neighbor
            if (mid > low && arr[mid - 1] == key) 
            {
                return mid - 1;
            }
            // Check right neighbor
            if (mid < high && arr[mid + 1] == key) 
            {
                return mid + 1;
            }
    
            if (arr[mid] > key) 
            {
                high = mid - 2;  
            } 
            else 
            {
                low = mid + 2;   
            }
        }
    return -1;
    }

    int findTarget(vector<int>& arr, int target) {
        return fun(arr, 0, arr.size() - 1, target);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends