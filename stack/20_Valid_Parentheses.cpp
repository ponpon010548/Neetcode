#include <string>
#include <vector>

/*   s = "({})[]"
 *   s.size = 6  -> s.size & 1 return false
 *   for(int i = 0; i < size; i++){
 *      if(s[i] != '{' && s[i] != '(' && s[i] != '['){
 *          v.push_back(s[i]);
 *      }
 *      else if(s[i] != v.back()){
 *          return false;
 *      }
 *   }
 *   return v.empty();
 *   =>  {    =>  ( => null => [ => done!
 *       (
 *   Time: O(n), Space: O(n)
 */


class Solution{
private:
    char getOpenBracket(char &c){
        if(c == '}'){
            return '{';
        }
        if(c == ')'){
            return '(';
        }
        return '[';
    }
public:
    bool isValid(std::string s){
        if(s.size() & 1){
            return false;
        }
        std::vector<char> stack;
        for(char &c: s){
            if(c == '{' || c == '(' || c == '['){
                stack.push_back(c);
            }
            else if(stack.empty() || (getOpenBracket(c) != stack.back())){
                return false;
            }
            else{
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};
