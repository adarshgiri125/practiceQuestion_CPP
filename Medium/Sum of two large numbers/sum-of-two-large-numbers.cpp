//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        int num=0;
        int carry=0;
        string ans="";
        char digit;
        while(X[0]=='0')
        {
            X= X.substr(1,X.length()-1);
        }
        while(Y[0]=='0')
        {
            Y= Y.substr(1,Y.length()-1);
        }
        if(X.length()==0&&Y.length()==0)
        return "0";
        else if(X.length()!=0&&Y.length()==0)
        return X;
        else if(X.length()==0&&Y.length()!=0)
        return Y;
        int index1=X.length()-1,index2=Y.length()-1;
        int len = min(X.length(),Y.length());
        for(int i=len-1;i>=0;i--)
        {
            num= (int)X[index1--]-48 + (int)Y[index2--]-48 + carry;
            if(num>9)
            {
                carry = (num-num%10)/10;
                digit = char(num%10)+'0';
                ans=digit+ans;
                
            }
            else
            {
                carry=0;
                digit=char(num)+'0';
                ans=digit+ans;
            }
        }
        if(X.length()!=Y.length()&&carry>0)
        {
            string a = X.length()>Y.length() ? X:Y;
            a = a.substr(0, a.length()-len);
            for(int i=a.length()-1;i>=0;i--)
            {
                num= (int)a[i]-48 + carry;
                if(num>9)
            {
                carry = (num-num%10)/10;
                digit = char(num%10)+'0';
                ans=digit+ans;
            }
            else
            {
                carry=0;
                digit=char(num)+'0';
                ans=digit+ans;
            }
            }
        }
        else if(X.length()!=Y.length()&&carry==0)
        {
            string a = X.length()>Y.length() ? X:Y;
            a = a.substr(0, a.length()-len);
            ans = a+ ans;
        }
        if(carry>0)
        {
            ans = to_string(carry)+ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends