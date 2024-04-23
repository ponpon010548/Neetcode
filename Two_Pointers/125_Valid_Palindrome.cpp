#include <string>

class Solution{
private:
    bool isAlphanumeric(char c){
        if(c >= 'a' && c <= 'z'){
            return true;
        }
        if(c >= 'A' && c <= 'Z'){
            return true;
        }
        if(c >= '0' && c <= '9'){
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(std::string s){
        int size = s.size(), i = 0, j = size - 1;
        while(i < size && !isAlphanumeric(s[i])) i++;
        while(j >= 0 && !isAlphanumeric(s[j])) j--;
        while(i < j){
            while(i < size && !isAlphanumeric(s[i])) i++;
            while(j >= 0 && !isAlphanumeric(s[j])) j--;
            if(s[i] != s[j]){
                if(s[i] <= '9' || s[j] <= '9'){
                    return false;
                }
                if((s[i] + 32 != s[j]) && (s[i] - 32 != s[j])){
                    return false;
                }
            }
            i++;
            j--;
        }
        return true;
    }
};
