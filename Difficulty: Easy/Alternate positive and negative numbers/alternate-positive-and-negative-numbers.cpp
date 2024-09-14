//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> negative;
        vector<int> positive;
        for(int i =0;i<arr.size();i++){
            if(arr[i]>=0) positive.push_back(arr[i]);
            else negative.push_back(arr[i]);
        }
        int n =0;
        int p =0;
        int i =0;
        while(n<negative.size() and p<positive.size()){
            if(i%2==0){
                arr[i] = positive[p];
                p++;
            }
            else{
                arr[i] = negative[n];
                n++;
            }
            i++;
        }
        while(n<negative.size()){
            arr[i] = negative[n];
            n++;i++;
        }
        while(p<positive.size()){
            arr[i] = positive[p];
            p++;i++;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends