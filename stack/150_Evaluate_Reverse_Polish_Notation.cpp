#include <vector>
#include <string>
/*
 *   [2, 1, +, 3, *]
 *  
 *   2  -> push, 1 -> push,  +: 1 + 2 = 3 -> push, 3 -> push -> *: 3 * 3 = 9
 *
 *  Time: O(n), Space: O(n)
 */
class Solution{
private:
    void cal(std::string &s, std::vector<int> &stack){
        int a, b, res;
        a = stack.back();
        stack.pop_back();
        b = stack.back();
        stack.pop_back();
        switch((char)s[0]){
            case '+':
                res = b + a;
                break;
            case '-':
                res = b - a;
                break;
            case '*':
                res = b * a;
                break;
            case '/':
                res = b / a;
                break;
            default:
                exit(1);
        }
        stack.push_back(res);
    }
public:
    int evalRPN(std::vector<std::string> &tokens){
        std::vector<int> stack;
        for(std::string &str: tokens){
            if(str == "+" || str == "-" || str == "/" || str == "*"){
               cal(str, stack); 
            }
            else{
                stack.push_back(std::stoi(str));
            }
        }
        return stack.back();
    }
};
