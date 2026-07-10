class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int left = 0;
        int maxfreq = 0;
        int maxlength = 0;
        for(int right = 0;right<s.size();right++){
            freq[s[right]]++;
            maxfreq = max(maxfreq,freq[s[right]]);

            while((right - left + 1) - maxfreq > k){
                freq[s[left]]--;
                left++;
            }
            maxlength = max(maxlength,right - left + 1);
        }
        return maxlength;
    }
};
