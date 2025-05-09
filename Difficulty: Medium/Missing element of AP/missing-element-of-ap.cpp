//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n=arr.size();
        int commonDiff;
        if(arr[1]-arr[0]<0)
        commonDiff=max(arr[1]-arr[0], arr[n-1]-arr[n-2]);
        else
        commonDiff= min(arr[1]-arr[0], arr[n-1]-arr[n-2]);
        int low = 0;
        int high = n-1;
        while(low < high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid] == arr[0] + commonDiff*mid)
            {   low = mid+1;
                
            }
            else{
                high = mid;
            }
        }
        if(low==n-1)
        {
            if(arr[n-1]-arr[n-2]!=(commonDiff))
            return arr[n-1]-commonDiff;
            else
            return arr[0]+commonDiff*(low+1);
        }
        
        return arr[0] + commonDiff*low;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends