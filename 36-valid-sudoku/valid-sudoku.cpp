class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //for rows
        for(int i = 0; i < 9; i++){
            unordered_set<char> st;
            for(int j = 0; j < 9; j++){
                char val = board[i][j];
                if(val == '.') continue;
                if(st.count(val)) return false;
                st.insert(val);
            }
        }    

        //for cols
        for(int j = 0; j < 9; j++){
            unordered_set<char> st;
            for(int i = 0; i < 9; i++){
                char val = board[i][j];
                if(val == '.') continue;
                if(st.count(val)) return false;
                st.insert(val);
            }
        }

        //for 3*3 grid
        for(int row = 0; row < 9; row += 3){
            for(int col = 0; col <9; col += 3){
                unordered_set<char> st;
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        char val = board[row+i][col+j];
                        if(val == '.') continue;
                        if(st.count(val)) return false;
                        st.insert(val);
                    }
                }
            }
        }
        return true;
    }
};