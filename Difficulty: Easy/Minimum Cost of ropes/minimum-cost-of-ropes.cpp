//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
       priority_queue<long long,vector<long long>, greater<long long> > pq;
       
       for(int i = 0; i<arr.size(); i++){
           pq.push(arr[i]);
       }
       
       long long ans = 0;
       while(pq.size() > 1){
           int f = pq.top();
           pq.pop();
           int s = pq.top();
           pq.pop();
       
           long long sum = f + s;
           ans += sum;
           pq.push(sum);
       }
       
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends