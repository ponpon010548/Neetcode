#include <unordered_set>
#include <vector>
class Solution{
    public:
        int longestConsecutive(std::vector<int> &nums){
            std::unordered_set<int> unset(nums.begin(), nums.end()); // O(n)
            int len = 1, m;
            for(int &n: nums){
                if(unset.find(n - 1) == unset.end()){
                    m = n + 1;
                    while(unset.find(m) != unset.end()){
                        ++m;
                    }
                    len = std::max(len, m - n);
                }
            } 
            return len;
        }
};
