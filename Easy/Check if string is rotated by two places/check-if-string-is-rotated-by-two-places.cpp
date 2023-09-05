//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
       if(str1.size() != str2.size()) return 0;
       if(str1.size()==1 && str2.size()==1){
            if(str1==str2){
                return 1;
            }
            return 0;
        }
       
       int left = 1, right = 1;
       int n = str1.size();
       for(int i = 0; i<n; i++){
           if(str1[(i+2)% n] != str2[i]){
               left = 0;
           }
       }
       for(int i = 2; i<n; i++){
           if(str1[i] != str2[(i + 2) % n]){
               right = 0;
           }
       }
       
       return left || right;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends