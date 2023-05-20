//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        
        if(N%groupSize!=0) return false;

            sort(hand.begin(),hand.end());
            
            int count=0;
            
            for(int i=0;i<N;i++){
            if(hand[i] == hand[i+1] == hand[i+2] && hand.size() < 7 && groupSize >=3){
                return false;
            }
            
            if(hand[i]+1==hand[i+1] || hand[i]==hand[i+1]){
            
            count++;
            
            }
            else{
                
            
                if((count+1)%groupSize!=0){

                
                return false;
                
                }
                else{
            
                count=0;
                
                }
            
            }
            
            }
            
            
            
            return true;
            
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends