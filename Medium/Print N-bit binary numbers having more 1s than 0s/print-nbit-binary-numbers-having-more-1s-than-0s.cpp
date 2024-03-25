//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void solve(vector<string>&ans,string t,int o,int z,int n){
        
        if(z>o)return;
        
        if(t.length()==n){
            ans.push_back(t);
            return;
        }
  
             solve(ans,t+'1',o+1,z,n);
             solve(ans,t+'0',o,z+1,n);
 
    }
    
vector<string> NBitBinary(int n){
    // Your code goes here
    
    vector<string>ans;
    string t="";
    solve(ans,t,0,0,n);
    
    return ans;
}

};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends