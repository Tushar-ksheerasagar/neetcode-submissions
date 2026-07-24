class Solution {
public:
    vector<int> cur;
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums,int index,int target){
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        if(index == nums.size() || target < 0) return;
        cur.push_back(nums[index]);
        backtrack(nums,index,target - nums[index]);
        cur.pop_back();
        backtrack(nums,index+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums,0,target);
        return ans;
    }
};
