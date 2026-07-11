class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> list;
        deque<int> dq;
        for(int i = 0;i<nums.size();i++){
            // Remove indices outside the current window
            if(!dq.empty() && dq.front()<= i - k){
                dq.pop_front();
            } 
            // Remove smaller elements from the back
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            // Add current index
            dq.push_back(i);
            // Store the maximum of the current window
            if(i>=k-1) list.push_back(nums[dq.front()]);
        }
        return list;
    }
};
