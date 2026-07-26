class Solution {
   public:
    vector<string> ans;
    vector<string> mapping = {
        "",      // 0
        "",      // 1
        "abc",   // 2
        "def",   // 3
        "ghi",   // 4
        "jkl",   // 5
        "mno",   // 6
        "pqrs",  // 7
        "tuv",   // 8
        "wxyz"   // 9
    };
    void backtrack(string& digits, int idx, string& cur) {
        if (idx == digits.size()) {
            ans.push_back(cur);
            return;
        }
        string letters = mapping[digits[idx] - '0'];
        for (char ch : letters) {
            cur.push_back(ch);
            backtrack(digits, idx + 1, cur);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string cur;
        backtrack(digits, 0, cur);
        return ans;
    }
};