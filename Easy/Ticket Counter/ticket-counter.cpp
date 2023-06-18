//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int> &store, int k) {
    bool front = true;
        while (store.size() > 1) {
            if (front) {
                for (int i = 0; i < k; ++i) {
                    store.erase(store.begin());
                    if (store.size() == 1) {
                        break;
                    }
                }
            } else {
                for (int i = 0; i < k; ++i) {
                    store.pop_back();
                    if (store.size() == 1) {
                        break;
                    }
                }
            }
            front = !front;
        }
        return store[0];
    }

    int distributeTicket(int N, int K) {
        vector<int> store;
        for (int i = 1; i <= N; ++i) {
            store.push_back(i);
        }
        return solve(store, K);
    }


};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends