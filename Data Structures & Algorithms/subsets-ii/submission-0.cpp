class Solution {
public:
    vector<int> cur;
    vector<vector<int>> ans;
    void backtrack(vector<int> & nums,int index){
        ans.push_back(cur);
        for(int i = index;i<nums.size();i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            backtrack(nums,i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return ans;
    }
};
