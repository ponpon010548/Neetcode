#include <iostream>
#include <vector>

class Solution{
    public:
        std::vector<int> productExceptSelf(std::vector<int> &nums){
            std::vector<int> prod(nums.size(), 1);
            //prefix
            for(int i = 1; i < nums.size(); i++){
                prod[i] *= (nums[i - 1] * prod[i - 1]);
            }
            //suffix
            int tmp = 1;
            for(int i = nums.size() - 2; i >= 0; i--){
                tmp *= nums[i + 1];
                prod[i] *= tmp;
            }
            return prod;
        }
};
