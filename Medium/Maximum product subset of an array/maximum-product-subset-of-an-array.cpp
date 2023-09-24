//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&arr, int n){
        //Write your code here  
        long long int mod = 1e9 + 7;
        sort(arr.begin(),arr.end());
        int count = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] < 0){
                count++;
            }
            else{
                break;
            }
        }
        
        bool check = false;
        if(count % 2 == 0){
            check = true;
        }
 
        long long int ans = 1;
        if(arr[n-1] == 0 && count == 1 || count == 0 && arr[n-1] == 0){
            return 0;
        }
        
        for(int i = n-1; i>=0; i--){
            if(arr[i] > 0) ans = (ans * arr[i]) % mod;
            else break;
             
        }
        
        for(int i = 0; i< n; i++){
            if(arr[i] < 0){
                if(check == true) ans = (ans * arr[i]) % mod;
        
                else if(count > 1){
                    ans = (ans * arr[i]) % mod;
                    count--;
                }
            }
            else break;
            
        }
        if(arr[n-1] <= -1 && n == 1) return arr[n-1];
        return ans;
        
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends