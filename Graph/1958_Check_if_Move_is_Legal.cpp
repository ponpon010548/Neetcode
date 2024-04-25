#include <vector>

class Solution {
public:
    bool checkMove(std::vector<std::vector<char>>& board, int rMove, int cMove, char color) {
        std::vector<std::vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1,1}, {-1,1}, {1,-1}, {-1,-1}};
        char opColor = (color == 'W' ? 'B': 'W');
        int r, c;
        bool check_begin = false;
        for(int i = 0; i < 8; i++){
            check_begin = true;
            r = rMove;
            c = cMove;
            while((r + dir[i][0] >= 0) && (r + dir[i][0] < 8) && \
                    (c + dir[i][1] >= 0) && (c + dir[i][1] < 8)){
                r += dir[i][0];
                c += dir[i][1];
                if(check_begin){
                    check_begin = false;
                    if(board[r][c] != opColor){
                        break;
                    }
                }
                if(board[r][c] == '.'){
                    break;
                }
                if(board[r][c] == color){
                    return true;
                }
            }
        }
        return false;
    }
};