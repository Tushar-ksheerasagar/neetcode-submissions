class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> row,col,boxes;
        for(int r = 0;r<9;r++){
            for(int c = 0;c<9;c++){
                if(board[r][c] == '.') continue;
                int box = (r/3)*3 + (c/3);
                char num = board[r][c];
                if(row[r].count(num) || col[c].count(num) || boxes[box].count(num)){
                    return false;
                }
                row[r].insert(num);
                col[c].insert(num);
                boxes[box].insert(num);
            }
        }
        return true;
    }
};
