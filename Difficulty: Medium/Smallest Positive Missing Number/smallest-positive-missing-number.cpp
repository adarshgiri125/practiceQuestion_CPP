//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        //int mini= INT_MAX ;
        int n=arr.size();
        int j = 1;
        int count  =0; 
        
        sort(arr.begin(),arr.end());
        for(int i=0 ; i<n ;i++){
            if(arr[i]>0){
               if(arr[i]!=j){
                   return j;
               }
               if(arr[i]!=arr[i+1]){
                j++;    
               }
               
            }
         
        }
        for(int i = 0;i< n; i++){
            if(arr[i]<=0){
                count++;
            }
            
        }
        if(count == n){
            return 1;
        }
        
        
        return arr[n-1]+1;
    }

};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends