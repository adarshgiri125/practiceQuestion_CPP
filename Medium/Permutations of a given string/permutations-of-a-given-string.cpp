//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void solve(string s, set<string> &ans, int start){
	        if(start >= s.size()){
	            ans.insert(s);
	            return;
	        }
	        
	        for(int i = start; i<s.size(); i++){
	           
	           swap(s[i], s[start]);
	           solve(s,ans,start+1);
	          
	            
	        }
	        
	    }
		vector<string>find_permutation(string s)
		{
		    
		    set<string> ans;
		    vector<string> str;
		    solve(s,ans,0);
		    for(auto i : ans){
		        str.push_back(i);
		    }
		    sort(str.begin(), str.end());
		    
		    
		    return str;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends