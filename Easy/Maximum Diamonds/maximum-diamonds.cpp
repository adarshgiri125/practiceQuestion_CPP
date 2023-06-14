//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // long long maxDiamonds(int A[], int N, int K) {
    //     sort(A , A+N);
    //     int sum = 0;
    //     for(int i = N-1; i>=0 && K>=1; i--){
    //         sum += A[i];
    //         A[i] = A[i]/2;
    //         if(A[i] >= A[i-1]){
    //             i++;
    //         }
            
    //     }
    //     return sum;
    // }
    long long maxDiamonds(int A[], int N, int K) {
    priority_queue<int> store;
    for(int i = 0; i<N; i++) store.push(A[i]);

    long long sum = 0;
    for(int i = 0; i<K; i++){
        int ele = store.top();
        sum += ele;
        ele = ele/2;
        
        
        store.pop();
        store.push(ele);
        
        
    }
    
    return sum;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends