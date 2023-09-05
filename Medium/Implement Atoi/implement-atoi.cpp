//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int sum = 0;
        int start = 0;
        bool a = false;
        if (str[0] == '-') {
            start = 1;
            a = true;
        }
        for(int i = start; i<str.size();i++){
            if(str[i]>='0' && str[i]<='9'){
            sum = sum* 10 + (str[i]-'0');
            }
            else{
                return -1;
            }
        }
        if(a == true){
            return -sum;
        }
        return sum;
    
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends