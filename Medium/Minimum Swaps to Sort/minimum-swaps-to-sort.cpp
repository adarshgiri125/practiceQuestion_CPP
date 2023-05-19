//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int> >store;
	    for(int i = 0; i<nums.size(); i++){
	        store.push_back({nums[i], i});
	    }
	    
	    sort(store.begin(),store.end());
	    int count = 0;
	    
	    for(int i = 0; i<store.size(); i++){
	        if(store[i].second != i){
	            count++;
	            swap(store[i], store[store[i].second]);
	            i--;
	        }
	    }
	    
	    return count;
	      
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends