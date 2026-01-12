class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int> dq;
        int j = 0;
        vector<int> ans;
        
        for(int i = 0; i<arr.size(); i++){
            while(!dq.empty() && arr[dq.back()] <=  arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(j > dq.front()){
                dq.pop_front();
                    
            }
            
            if(i - j + 1 >= k){
                ans.push_back(arr[dq.front()]);
                j++;
            }
        }
        return ans;
    }
};