//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
       int n = arr.size();
       vector<int> left(n,0);
       vector<int> right(n,0);
       
       stack<int> s;
       s.push(0);
       for(int i = 0; i<n; i++){
           while(arr[i] <= s.top()){
               s.pop();
           }
 
           left[i] = s.top();
           
           s.push(arr[i]);
       }
       
       stack<int> s1;
       s1.push(0);
       
       for(int i = n - 1; i>=0; i--){
           while(arr[i] <= s1.top()){
               s1.pop();
           }
          
           right[i] = s1.top();
           
           s1.push(arr[i]);
       }
       
       int ans = 0;
       for(int i = 0; i<n; i++){
           ans = max(ans, abs(right[i] - left[i]));
       }
       
       
       return ans;
       
       
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends