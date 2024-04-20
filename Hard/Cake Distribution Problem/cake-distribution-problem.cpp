//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool isPossible(int mid, vector<int>& arr, int m, int n){
        int sum = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            sum+=arr[i];
            if(sum>=mid){
                
                cnt++;
                sum=0;
            }
        }
        if(cnt<m){
            return false;
        }
        return true;
    }
    int maxSweetness(vector<int>& arr, int n, int m) {
        
        m = m + 1;
        if(n < m){
            return -1;
        }
        int i = 0;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        
        int s = *min_element(arr.begin(),arr.end());
        int e = sum;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while(s <= e){
            
            if(isPossible(mid,arr,m,n)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
            
        }
        
        return ans;
    }
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends