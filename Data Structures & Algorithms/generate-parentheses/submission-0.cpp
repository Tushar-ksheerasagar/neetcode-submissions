class Solution {
public:
    vector<string> ans;
    void backtrack(string &cur,int open,int close,int n){
        if(cur.size() == 2*n){
            ans.push_back(cur);
            return;
        }
        if(open < n){
            cur.push_back('(');
            backtrack(cur,open+1,close,n);
            cur.pop_back();
        }
        if(close < open){
            cur.push_back(')');
            backtrack(cur,open,close+1,n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur;
        backtrack(cur,0,0,n);
        return ans;
    }
};
