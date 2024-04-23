#include <vector>
/*
 * Time: O(n), space: O(1)
 * [1, 2, 3, 4, 5, 6] , target = 8
 *  i              j
 *  i + j < target => i++;
 *
 */ 
class Solution{
public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target){
        int i = 0, j = numbers.size() - 1, sum;
        while(numbers[i] + numbers[j] != target){
            sum = numbers[i] + numbers[j];
            if(sum < target){
                i++;
            }
            else if(sum > target){
                j--;
            }
        }
        return {i+1, j+1};
    }
};
