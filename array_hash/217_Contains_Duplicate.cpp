#include <iostream>
#include <vector>
#include <unordered_set>

/* [1, 2, 3, 1]
 * use unordered_set
 * check 1 in set?
 * No, push 1 -> [1]
 * check 2 in set?
 * No, push 2 -> [2]
 * check 3 in set?
 * No, push 3 -> [3]
 * check 1 in set?
 * Yes, return false
 * Support vector.size() = N
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
class Solution{
    public:
        bool containsDuplicate(std::vector<int> &nums){
            std::unordered_set<int> appear;
            for(int &n: nums){
                if(appear.find(n) != appear.end()){
                    return true;
                }
                appear.insert(n);
            }
            return false;
        }
};


