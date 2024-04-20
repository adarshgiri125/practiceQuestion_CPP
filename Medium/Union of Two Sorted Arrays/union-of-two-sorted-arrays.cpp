//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        unordered_map<int,int> mp;
        unordered_map<int,bool> mp2;
        
        for(int i = 0; i<n; i++){
            mp[arr1[i]]++;
        }
        for(int i = 0; i<m; i++){
            mp[arr2[i]]++;
        }
        
        for(int i = 0; i<n; i++){
            if(mp2[arr1[i]] != true)
                 ans.push_back(arr1[i]);
            mp2[arr1[i]] = true;
        }
        for(int i = 0; i<m; i++){
            if(mp2[arr2[i]] != true)
                 ans.push_back(arr2[i]);
            mp2[arr2[i]] = true;
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends