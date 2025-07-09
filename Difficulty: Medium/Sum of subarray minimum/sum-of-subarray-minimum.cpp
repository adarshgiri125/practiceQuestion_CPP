class Solution {
  public:
    vector<int> getNSL(vector<int>& arr, int n){
        vector<int> res(n);
        stack<int> st; // stores the index of the elemnt less than the current element 
        for(int i = 0; i < n; i++){
            if(st.empty() == true){
                res[i] = -1; // no element is less than the current element 
            }
            else{
                while(!st.empty() && arr[st.top()] >= arr[i]){ // = because we are considering no duplictae 
                // subarray will not be counted if duplictaed elemnt exist
                    st.pop();
                }
                res[i] = st.empty() ? -1 : st.top();
            }   
            st.push(i);
        }
        return res;
    }
    
    vector<int> getNSR(vector<int>& arr, int n){
        vector<int> res(n);
        stack<int> st; // stores the index of the elemnt less than the current element 
        for(int i = n - 1; i >= 0; i--){
            if(st.empty() == true){
                res[i] = n; // no element is less than the current element 
            }
            else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }
                res[i] = st.empty() ? n : st.top();
            }   
            st.push(i);
        }
        return res;
    }
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        /* brute force - generating all the subaarays
        int res = 0;
        for(int i=0;i<n;i++){
            int mini = arr[i];
            for(int j=i;j<n;j++){
                mini = min(arr[j], mini);
                res += mini;
            }
        }
        return res;
        */
        
        vector<int> NSL = getNSL(arr,n); // stores the next smaller element on the left side
        vector<int> NSR = getNSR(arr,n); // stores the next smaller element on the right side
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            int ls = i - NSL[i]; // count how many elements are less than the the current element on left side
            int rs = NSR[i] - i; // count how many elements are less than the the current element on right side
            
            int totalways = ls * rs;
            int totalsum = arr[i] * totalways;
            
            sum = sum + totalsum;
        }
        return sum;
    }
};