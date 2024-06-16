//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
   bool isPrime(int n)
{
    
    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
    void prime(int n,map<int,int> &mp){
        for(int i = 2; i <= n; i++){
            if(isPrime(i)) mp[i]++;
        }
      
    }
    vector<int> getPrimes(int n) {
       map<int,int>mp;
        
        prime(n,mp);
   
        for(auto i : mp){
            int u = -1;
            if(i.second > 0)  u = i.first;
            if(u == 524) 
            int v = n - u;
            if(mp[v] > 0) return {u,v};
        }
        
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends