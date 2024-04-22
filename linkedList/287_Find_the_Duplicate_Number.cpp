#include "linkedList.h"
#include <vector>
/* [1, 3, 4, 2, 2]
 * 4 + 1 = 5 integers, [1, 4]
 * the arr size must be n + 1
 * if we travel this arr by arr[i] as idx
 * then
 * arr[1] -> arr[3] -> arr[4] -> arr[2] -> arr[4] -> arr[2] -> ...
 *
 */
class Solution{
public:
    int findDuplicate(std::vector<int>& nums){
        int slow = 0, fast = 0, entry = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        while(slow != entry){
            slow = nums[slow];
            entry = nums[entry];
        }
        return slow;
    }
};
