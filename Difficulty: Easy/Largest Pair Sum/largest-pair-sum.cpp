//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int m1 = 0;
        int m2 = 0;
        int n = arr.size();
        
        for(int i = 0; i<n; i++){
            if(m1 < arr[i]){
                m2 = m1;
                m1 = arr[i];
            }
            else if(m2 < arr[i]){
                m2 = arr[i];
            }
        }
        
        return m1 + m2;
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
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends