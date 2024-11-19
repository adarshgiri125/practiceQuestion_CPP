//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            reverse(arr.begin()+i+1,arr.end());
            int index=upper_bound(arr.begin()+i+1,arr.end(),arr[i])-arr.begin();
            swap(arr[i],arr[index]);
            for(int j=index;j<n-1;j++)
            {
                if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
            }
            break;
            
        }
        else if(i==0)
        {
            reverse(arr.begin(),arr.end());
        }
    }
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends