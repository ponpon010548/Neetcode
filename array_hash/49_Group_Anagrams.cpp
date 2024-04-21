#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/* strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * "eat" -> "aet"   "aet": {"eat"}
 * "tea" -> "aet"   "aet": {"eat", "tea"}
 * Time: n * s -> n: number of strings, s: str len
 * space: n * s 
 */


class Solution{
    private:
        std::string cntSort(std::string s){
            int cnt[26] = {0};
            for(char &c: s){
                cnt[c - 'a']++;
            }
            int idx = 0;
            for(int i = 0; i < 26; i++){
                while(cnt[i] > 0){
                    s[idx] = i + 'a';
                    ++idx;
                    --cnt[i];
                }
            }
            return s;
        }
    public:
        std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
            std::unordered_map<std::string, std::vector<std::string>> umap;
            std::vector<std::vector<std::string>> res;
            for(std::string &s: strs){
                std::string sortedStr = cntSort(s);
                umap[sortedStr].push_back(s);
            }
            for(auto &val: umap){
                res.push_back(val.second);
            }
            return res;
        }
};
