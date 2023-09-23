//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    //Function to find list of all words possible by pressing given numbers.
    void solve(int a[], int n,string s[],vector<string> &ans,int index,string temp ){
        if(index >= n){
            ans.push_back(temp);
            return;
        }
        
        int x = a[index];
        string t = s[x];
        for(int i = 0; i<t.size(); i++){
            temp.push_back(t[i]);
            solve(a,n,s,ans,index+1,temp);
            temp.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
     
        string s[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        vector<string> ans;
        string temp = "";
        solve(a,n,s,ans,0,temp);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends