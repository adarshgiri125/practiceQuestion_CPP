//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        int total_arr_sum=0;
        for(auto it:arr)
        total_arr_sum += it;
        
        int first=-1;
        int second=-1;
        int temp=0;
        
        //for first subarray
        int current_sum=0;
        while(temp<arr.size()){
            
            current_sum += arr[temp];
            
            if(current_sum*3 == total_arr_sum){
                first = temp;
                temp++;
                break;
            }
            
            else if(current_sum*3 >total_arr_sum)
                return {-1,-1};
                
            else
            temp++;
        }
        
        //for second subarray
        current_sum = 0;
        while(temp<arr.size()){
            
            current_sum += arr[temp];
            
            if(current_sum*3 == total_arr_sum){
                second = temp;
                temp++;
                break;
            }
            
            else if(current_sum*3 >total_arr_sum)
                return {-1,-1};
                
            else
            temp++;
        }
        
        
        //for third subarray
        current_sum=0;
        while(temp<arr.size()){
            
            current_sum += arr[temp];
            
            if(current_sum*3 == total_arr_sum)
                return {first,second};
            
            else if(current_sum*3 >total_arr_sum)
                return {-1,-1};
            
            else
            temp++;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends