class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void backtrack(vector<int> &nums,int index){
        if(index == nums.size()){ 
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[index]);
        backtrack(nums,index+1);
        cur.pop_back();
        backtrack(nums,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums,0);
        return ans;
    }
};
