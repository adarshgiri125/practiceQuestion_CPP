//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        
        vector<pair<int,int> > v;
        
        for(auto i : mp){
            v.push_back({i.first,i.second});
        }
        
        auto compare = [](pair<int,int> a, pair<int,int> b){
            if(a.second > b.second){
                 return true;   
            }
            else if(a.second == b.second){
                return a.first < b.first;
            }
            else return false;
        
        };
        
        // for(auto i : v){
        //     cout << i.first << " " << i.second << endl;
        // }
        
        sort(v.begin(),v.end(), compare);
        
        int k = 0;
        for(int i = 0; i<v.size(); i++){
            int u = v[i].second;
            
            while(u > 0){
               arr[k] = v[i].first;
               k++;
               u--;
            }
        }
        
        return arr;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends