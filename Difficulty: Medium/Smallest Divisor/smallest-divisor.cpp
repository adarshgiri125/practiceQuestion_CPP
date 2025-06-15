class Solution {
public:
    bool possible(int divisor, vector<int>& arr, int k) {
        int q = 0;
        for(int val : arr) {
            q += val / divisor;
            if (val % divisor > 0) q += 1;
        }
        return q <= k;
    }

    int smallestDivisor(vector<int>& arr, int k) {
        int s = 1;
        int e = *max_element(arr.begin(), arr.end());
        int ans = e;

        while(s <= e){
            int mid = (s + e) / 2;
            if(possible(mid, arr, k)){
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
