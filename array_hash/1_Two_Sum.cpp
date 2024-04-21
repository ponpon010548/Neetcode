#include <iostream>
#include <unordered_map>
#include <vector>

class Solution{
    public:
        std::vector<int> twoSum(std::vector<int> &nums, int target){
            std::unordered_map<int, int> umap;
            std:: vector<int> res;
            for(int i = 0; i < nums.size(); i++){
                std::unordered_map<int, int>::iterator it = umap.find(target - nums[i]);
                if(it != umap.end()){
                    res = {it->second, i};
                    break;
                }
                umap[nums[i]] = i;
            }
            return res;
        }
};
