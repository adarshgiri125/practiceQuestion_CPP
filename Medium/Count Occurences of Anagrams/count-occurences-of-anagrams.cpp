//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:

    bool check(vector<int> &freq,vector<int> &freq2){
        
        for(int i = 0; i<26; i++){
            if(freq[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
	int search(string pat, string txt) {
	    vector<int> freq(26,0);
	    vector<int> freq2(26,0);
	    int ans = 0;
	    
	    for(int i = 0; i<pat.size(); i++){
	        int index = pat[i] - 'a';
	        freq[index]++;
	    }
	    
	    int i = 0;
	    int k = pat.size();
	    while(i < k){
	        int index = txt[i] - 'a';
	        freq2[index]++;
	        i++;
	        
	    }
	    if(check(freq,freq2)) ans++;
	    
	    while(i < txt.size()){
	        char newchar = txt[i];
	        int index = newchar - 'a';
	        
	        freq2[index]++;
	        
	        char oldchar = txt[i - k];
	        int ind = oldchar - 'a';
	        freq2[ind]--;
	        
	        if(check(freq,freq2)) ans++;
	        i++;
	    }
	    
	    
	    return ans;
	    
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends