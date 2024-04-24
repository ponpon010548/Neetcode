#include <vector>
/*          1 2 3 4 5          1 2 3 4 5
 *              r                r
 *          1 2   4 5          1   3 4 5
 *        ->T(2)* T(2)      ->T(1)*T(3)
 * base case: T(0) = 1, T(1) = 1
 *            T(n) = T(0) * T(n - 1) + T(1) * T(n - 2) + ... + T(n-2) * T(1) + T(n - 1) * T(0)
 */

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> nums(n + 1, 0);
        nums[0] = 1;
        nums[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                nums[i] += (nums[j - 1] * nums[i - j]);
            }
        }
        return nums[n];
    }
};