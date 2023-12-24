//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int a[]){
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({a[i],i+1});
        }
        sort(vp.begin(),vp.end());
        int i=0;
        int ans=0;
        while(i<n&&k>0)
        {
            while(vp[i].second!=0&&k>=vp[i].first)
            {
                k-=vp[i].first;
                ans++;
                vp[i].second--;
            }
            i++;
        }
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
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends