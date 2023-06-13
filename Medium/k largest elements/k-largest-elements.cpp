//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    vector<int> kLargest(int arr[], int n, int k) {
        vector<int> ans;
        priority_queue<int> pq;
    
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
    
        while (k > 0 && !pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
            k--;
        }
    
        return ans;
    }

// 	vector<int> kLargest(int arr[], int n, int k) {
// 	    vector<int> ans;
// 	    int size = 1000000;
// 	    int store[size] = {-1};
	    
// 	    for(int i = 0; i<n; i++) store[arr[i]]++;
	    
	    
//         for(int i = size-1; i>=0; i--){
//             if(store[i] != 0){
//                 ans.push_back(i);
//                 k--;
//                 if(k==0){
//                     break;
//                 }
//             }
//         }
//         // for(int i = size-1; i>=size-6; i--){
//         //     cout<< store[i]<< " ";
//         // }
        
//         return ans;
	    
	    
	    
// 	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends