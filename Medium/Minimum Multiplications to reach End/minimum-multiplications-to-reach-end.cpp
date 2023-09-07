//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        queue<pair<int,int> > pq;
        vector<int> steps(100000, 1e9);
        
        pq.push({start,0});
        steps[start] = 0;
        
        while(!pq.empty()){
            
           int node =  pq.front().first;
           int step = pq.front().second;
           pq.pop();
           
           
           
           for(int i = 0; i<n; i++){
                int newnode = (node * arr[i]) % 100000;
                    if(step + 1 < steps[newnode]){
                        steps[newnode] = step + 1;
                        
                        if(newnode == end) return step + 1;
                        
                        pq.push({newnode,step + 1}); 
                        
                    }
           
           } 
        }
        if(start == end){
            return 0;
        }
        return -1;
        
    
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends