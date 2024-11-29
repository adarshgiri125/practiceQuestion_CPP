//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
       string ans = "";
       int n = s1.size();
       int m = s2.size();
       int i =  0;
       int j = 0;
       while(i<n && s1[i]=='0') i++;
       while(j<m && s2[j]=='0') j++;
       s1 = s1.substr(i,n-i+1);
       s2 = s2.substr(j,m-j+1);
       
       n = s1.size();
       m = s2.size();
       
       if(s2=="") return s1;
       if(s1=="") return s2;
       i = n-1;
       j = m-1;
       int carry = '0';
       while(i>=0 && j>=0){
           if(s1[i]+s2[j]+carry==('1'+'1'+'0')){
               carry='1';
               ans = '0'+ans;
           }
           else if(s1[i]+s2[j]+carry==('1'+'0'+'0')){
               carry = '0';
               ans = '1'+ans;
           }
           else if(s1[i]+s2[j]+carry==('0'+'0'+'0')){
               carry = '0';
               ans = '0'+ans;
           }
           else if(s1[i]+s2[j]+carry==('1'+'1'+'1')){
               carry = '1';
               ans = '1'+ans;
           }
           i--;
           j--;
       }
       while(i>=0){
           if(s1[i]+carry=='1'+'1'){
               carry = '1';
               ans = '0'+ans;
           }
           else if(s1[i]+carry=='1'+'0'){
               carry = '0';
               ans = '1'+ans;
           }
           else if(s1[i]+carry=='0'+'0'){
               carry = '0';
               ans = '0'+ans;
           }
           i--;
       }
       while(j>=0){
           if(s2[j]+carry=='1'+'1'){
               carry = '1';
               ans = '0'+ans;
           }
           else if(s2[j]+carry=='1'+'0'){
               carry = '0';
               ans = '1'+ans;
           }
           else if(s2[j]+carry=='0'+'0'){
               carry = '0';
               ans = '0'+ans;
           }
           j--;
       }
       if(carry=='1'){
           ans = '1'+ans;
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends