#include <string>
#include <vector>
/*                                (
 *                            ((      ()
 *                         (((  (()   ()(  
 *     
 *
 *
 *
 */ 
class Solution{
private:
    void gen(std::vector<std::string> &res, std::string &cur, int open, int &n){
        if(cur.size() == n * 2){
            res.push_back(cur);
            return;
        }
        if(open < n){
            cur.push_back('(');
            gen(res, cur, open + 1, n);
            cur.pop_back();
        }
        if((open << 1) > cur.size()){
            cur.push_back(')');
            gen(res, cur, open, n);
            cur.pop_back();
        }
    }
public:
    std::vector<std::string> generateParenthesis(int n){
        std::vector<std::string> res;
        std::string cur;
        gen(res, cur, 0, n);
        return res;
    }
};
