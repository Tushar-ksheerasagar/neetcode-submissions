class Solution {
public:
    vector<int> cur;
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums,int start,int target){
        if(target == 0) {
            ans.push_back(cur);
            return;
        }    
        for(int i = start;i<nums.size();i++){
            if(i>start && nums[i] == nums[i-1]) 
                continue;
            if(nums[i] > target)
                break;
            cur.push_back(nums[i]);
            backtrack(nums,i+1,target - nums[i]);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return ans;
    }
};
