#include <vector>
#include <iostream>

class Solution{
    public:
        bool isAnagram(std::string s, std::string t){
            if(s.size() != t.size()){
                return false;
            }
            std::vector<int> cnt(26, 0);
            for(char &c: s){
                ++cnt[c - 'a'];
            }
            for(char &c: t){
                --cnt[c - 'a'];
                if(cnt[c-'a'] < 0){
                    return false;
                }
            }
            return true;
        }
};
