#include <vector>
#include <algorithm>

/*   [10, 1, 2, 7, 1, 6],  p = 2
 * sort -> [1, 1, 2, 6, 7, 10]
 *             i
 *   cmp:  (nums[1] - nums[0], nums[2] - nums[1])
 *          1 1 2 6 7 10
 *       1    0 1 5 6  9
 *       1      1 5 6  9
 *       2        4 5  8
 *       6          1  4
 *       7             3
 *       10
 * p(1) = 
 * p(2) = p(1)
 *             
 *
 *  
 */
class Solution{
    int minimizeMax(std::vector<int> &nums, int p){
        
    }
}
