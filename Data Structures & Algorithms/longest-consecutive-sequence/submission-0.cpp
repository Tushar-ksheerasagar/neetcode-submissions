class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int longest = 0;
        for(int num : nums){
            if(!st.count(num - 1)){
                int currentnum = num;
                int currentstreak = 1;
                while(st.count(currentnum + 1)){
                    currentnum++;
                    currentstreak++;
                }
                longest = max(longest , currentstreak);
            }
        }
        return longest;
    }
};
