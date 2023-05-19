//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n, int m, int x)
    {
        vector<int> sorted;
        int i = 0;
        int j = 0;
        int k = 0;
        


        while(i < n && j < m){
             if(nums1[i] >= nums2[j]){
                 sorted.push_back(nums2[j]);
                 j++;

             }
             else{
                 sorted.push_back(nums1[i]);
                 i++;
             } 
             k++;
        }
        while(i < n){
            sorted.push_back(nums1[i]);
            i++;
            k++;

        }
        while(j < m){
            sorted.push_back(nums2[j]);
            j++;
            k++;
        }  
        
        
        return sorted[x-1];
    }
    
    
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends