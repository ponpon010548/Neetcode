#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> umap;
        vector<bool> pat(26, 0);
        string word;
        int idx = 0, sz = s.size(), space = 0;
        for(char &c: pattern){
            word = "";
            while(idx < sz){
                if(s[idx] == ' '){
                    idx++;
                    space++;
                    break;
                }
                word += s[idx];
                idx++;
            }
            auto it = umap.find(word);
            if(it == umap.end()){
                if(pat[c - 'a']){
                    return false;
                }
                umap[word] = c;
                pat[c - 'a'] = true;
            }
            else if(it->second != c){
                return false;
            }
        }
        return space==(pattern.size() - 1);
    }
};
