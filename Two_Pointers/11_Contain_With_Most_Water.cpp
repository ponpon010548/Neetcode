#include <vector>
/*
 * [1, 8 , 6, 2, 5, 4, 8, 3, 7]
 *  i                        j   ->   (j - i) * min(1, 7) = 8 * 1 = 8
 *     i                     j   ->   (j - i) * min(7, 8) = 7 * 7 = 49
 *
 *
 */
class Solution{
public:
    int maxArea(std::vector<int>& height){
        int i = 0, j = height.size() - 1, maxA = 0, A;
        while(i < j){
            A = (j - i) * std::min(height[i], height[j]);
            maxA = std::max(maxA, A);
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxA;
    }
};
