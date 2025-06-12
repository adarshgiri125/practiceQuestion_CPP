class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
        for(int i = 0; i<arr.size(); i++){
            int val = arr[i];
            int rem = abs(arr[i] - x);
            if(rem != 0)
             pq.push({rem, (-1 *val)});
        }
        
        vector<int> ans;
        while(k > 0){
            ans.push_back((-1 * pq.top().second));
            pq.pop();
            k--;
        }
        
        return ans;
    }
};