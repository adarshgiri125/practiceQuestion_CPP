//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        if(n==1)return 0;
        if(arr[0]==0)return -1;
        
        
        int jumps=0;
        int l=0; int r=0;
        
        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                 if (i +arr[i]>=n) return jumps+1;
                farthest= max(farthest,i+arr[i]);
            }
            if(farthest<=r)return -1;
            l=r+1;
            r=farthest;
            jumps+=1;
        }
       
        return jumps;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends