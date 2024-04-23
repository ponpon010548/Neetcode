#include <algorithm>
#include <vector>

/*    -1, -1, 0, 1, 2
 *     p   i        j    ->    -1 -1 2
 *     p   i     j       
 *     p      i  j       ->    -1 0 1        
 *            p  i  j   
 *
 *
 */


class Solution{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums){
        std::sort(nums.begin(), nums.end());
        int size = nums.size(), i, j , sum;
        std::vector<std::vector<int>> res;
        for(int pivot = 0; pivot < size - 2; pivot++){
            if(nums[pivot] > 0){
                break;
            }
            if(pivot > 0 && nums[pivot] == nums[pivot - 1]){
                continue;
            }
            i = pivot + 1;
            j = size - 1;
            while(i < j){
                sum = nums[i] + nums[j] + nums[pivot];
                if(sum == 0){
                    res.push_back({nums[pivot], nums[i], nums[j]});
                }
                if(sum >= 0){
                    do{
                        --j;
                    }while(j > pivot && nums[j] == nums[j+1]);
                }
                else{
                    do{
                        ++i;
                    }while(i < size -1 && nums[i] == nums[i - 1]);
                }
            }
        }
        return res;
    }
};
