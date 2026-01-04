class Solution {
  public:
    bool isPossible(int maxi, vector<int> &arr, int k){
        int person = 1;
        int sum = 0;
        for(int i = 0; i<arr.size(); i++){
            if(sum + arr[i] > maxi){
                sum = arr[i];
                person++;
            }
            else{
                sum += arr[i];
            }
        }
        return person <= k;
        
    }
    int findPages(vector<int> &arr, int k) {
        if(arr.size() < k) return -1;
        // code here
        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        int ans = end;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(isPossible(mid,arr,k)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
        
    }
};