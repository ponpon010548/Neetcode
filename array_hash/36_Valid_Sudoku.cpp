#include <iostream>
#include <vector>
#include <cstring>

class Solution{
    public:
        bool isValidSudoku(std::vector<std::vector<char>>& board){
            // 1~9
            bool check[9] = {false};
            //check row
            for(int i = 0; i < 9; i++){
                std::memset((void*)&check, 0, sizeof(bool) * 9);
                for(int j = 0; j < 9; j++){
                    if(board[i][j] == '.'){
                        continue;
                    }
                    if(check[board[i][j] - '1']){
                        return false;
                    }
                    check[board[i][j] - '1'] = true;
                }
            }
            //check col
             for(int j = 0; j < 9; j++){
                std::memset((void*)&check, 0, sizeof(bool) * 9);
                for(int i = 0; i < 9; i++){
                    if(board[i][j] == '.'){
                        continue;
                    }                   
                    if(check[board[i][j] - '1']){
                        return false;
                    }
                    check[board[i][j] - '1'] = true;
                }
            }           
            //check 3-3 subboxes
            for(int blk = 0; blk < 9; blk++){
                int x = 3 * (blk / 3), y = 3 * (blk % 3);
                std::memset((void*)&check, 0, sizeof(bool) * 9);
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(board[x+i][y+j] == '.'){
                            continue;
                        }
                        if(check[board[x + i][y + j] - '1']){
                            return false;
                        }
                        check[board[x+i][y+j] - '1'] = true;
                    }
                }
            }
            return true;
        }
};
