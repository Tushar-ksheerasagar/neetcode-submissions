class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> s1count(26,0);
        vector<int> s2count(26,0);
        
        for(auto c:s1) s1count[c-'a']++;
        int left = 0;
        for(int right = 0;right<s2.size();right++){
            s2count[s2[right]-'a']++;
            if(right - left + 1 > s1.size()){
                s2count[s2[left] - 'a']--;  
                left++;
            }
            if(s1count == s2count) return true;
        }
        return false;
    }
};
