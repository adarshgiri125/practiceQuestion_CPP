//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	#include <unordered_map>

bool sameFreq(string s) {
    unordered_map<char, int> frequency;

    for (char c : s) {
        frequency[c]++;
    }

    unordered_map<int, int> countFrequency;

    for (const auto& pair : frequency) {
        countFrequency[pair.second]++;
    }

    if (countFrequency.size() == 1) {
        return true;  
    }

    if (countFrequency.size() == 2) {
        auto it = countFrequency.begin();
        int firstCount = it->first;
        int firstFrequency = it->second;
        ++it;
        int secondCount = it->first;
        int secondFrequency = it->second;

        // Check if we can remove one character to make frequencies equal.
        return ((firstFrequency == 1 && (firstCount == 1 || firstCount - 1 == secondCount)) ||
                (secondFrequency == 1 && (secondCount == 1 || secondCount - 1 == firstCount)));
    }

    return false;  // More than two different frequencies, impossible to make them equal.
}

};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends