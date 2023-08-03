//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
             int n=s.length();
            int count=0;
            
            if(s[0]=='.' || s[n-1]=='.')    return 0;
            for(int i=0;i<n-1;i++){
                if(s[i]=='.'&& s[i+1]=='.')  return 0;
                if(s[i]=='.')   count++;
            }
            if(count!=3){
                return 0;
            }
            string kemp;
            for(int i=0;i<n;i++){
                
            
                 kemp="";
                
                while(i<n && s[i]!='.'  ){
                    if(s[i]<'0' || s[i]>'9'){
                        return 0;
                    }
                    kemp+=s[i];
                    i++;
                }
                
                int temp=stoi(kemp);
                if(temp>255 ){
                    return 0;
                }
                
                if(temp==0 && kemp.length()==1){
                    continue;
                }
                
                int c=0;
                while(temp){
                    temp=temp/10;
                    c++;
                }
                if(c!=kemp.length()){
                    return 0;
                }
                
            }
            return 1;
        
        }

};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends